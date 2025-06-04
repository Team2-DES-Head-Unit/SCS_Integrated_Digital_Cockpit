#include <iostream>
#include <iomanip>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <memory>
#include <stdexcept>

extern "C" {
    #include <libxenvchan.h>
}

// Need to set according to xl list
#define DOMU1_ID 1
// #define DOMU2_ID 2

std::mutex mutex;
std::condition_variable condition;
std::string gear_state = "P";  // 기본 기어 상태
std::string previous_gear_state = "";  // 이전 기어 상태

struct ControlData {
    float throttle;
    float steering;
    float distance;
    float speed;
    uint8_t gear_P;
    uint8_t gear_D;
    uint8_t gear_R;
    uint8_t gear_N;
    uint8_t indicator_l;
    uint8_t indicator_r;
};

ControlData control_data;

// Python에서 기어 상태를 받는 함수
void receive_gear_state() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    // char buffer[1024] = {0};
    // ControlData control_data;
    // 소켓 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error" << std::endl;
        return;
    }

    // 포트 번호 재사용 설정
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        std::cerr << "Setsockopt error" << std::endl;
        return;
    }

    // 주소 설정
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(65432);

    // 소켓에 주소 바인딩
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return;
    }

    // 연결 대기
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen error" << std::endl;
        return;
    }

    std::cout << "Waiting for connection from Python..." << std::endl;

    // 클라이언트 연결 수락
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        std::cerr << "Accept error" << std::endl;
        return;
    }

    while (true) {
        int valread = read(new_socket, &control_data, sizeof(ControlData));
        if (valread > 0) {
            if (control_data.gear_P == 1) gear_state = "P";
            else if (control_data.gear_D == 1) gear_state = "D";
            else if (control_data.gear_R == 1) gear_state = "R";
            else if (control_data.gear_N == 1) gear_state = "N";

            // 속도, 거리 출력
            std::cout << "Gear: " << gear_state
                      << " | Throttle: " << control_data.throttle
                      << " | Steering: " << control_data.steering
                      << " | Speed: " << control_data.speed << " cm/s"
                      << " | Distance: " << control_data.distance << " cm"
                      << std::endl;
        }
    }

    close(new_socket);
    close(server_fd);
}

int get_domid(const std::string& name){
    std::string cmd = "xl domid " + name;
    std::array<char, 128> buffer;
    std::string result;

    std::cerr << "Running command: " << cmd << std::endl;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("Failed to run xl domid");

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    std::cerr << "Find Dom ID result : " << result << std::endl;

    return std::stoi(result);
}

void vchan_server(uint32_t domid){
    struct libxenvchan *server = libxenvchan_server_init(nullptr, domid, "piracer/hu", 0, 0);
    // logger, domain id,xenstore path, receive buffer(read) min size, send buffer(write) min size
    if (!server){
        std::cerr << "Failed to create vchan server : " << domid << std::endl;
        return;
    }

    std::cout << "Vchan server started : " << domid << std::endl;

    while (true){
        ControlData C_data;
        {
            std::lock_guard<std::mutex> lock(mutex);
            C_data = control_data; // safely copy control data
        }

        if (!libxenvchan_is_open(server)){
            std::cerr << "Client not connected\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            continue;
        }
        int space = libxenvchan_buffer_space(server);
        std::cerr << "available buffer space : " << space << std::endl;

        std::cout << "[Copied ControlData] "
              << "Gear: " << (C_data.gear_P ? "P" :
                            (C_data.gear_D ? "D" :
                            (C_data.gear_R ? "R" :
                            (C_data.gear_N ? "N" : "Unknown"))))
              << " | Speed: " << C_data.speed
              << " | Distance: " << C_data.distance
              << std::endl;

        // int send_byte = libxenvchan_write(server, &C_data, sizeof(C_data));
        if (space >= sizeof(ControlData)){
            libxenvchan_write(server, &C_data, sizeof(C_data));
        }
        std::cerr << "send byte size : " << send_byte << std::endl;
        // vchan structure, data, size
        if (send_byte <= 0){
            std::cerr << "Failed to write : " << domid << std::endl;
            // break;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // send every 100ms
    }
    libxenvchan_close(server);
}

int main() {
    // 기어 상태를 받는 쓰레드 시작
    std::thread receiver(receive_gear_state);

    // int dom_id = get_domid("hu");
    // int dom_id = 0;

    // std::thread domu1_server(vchan_server, dom_id);
    std::thread domu1_server(vchan_server, DOMU1_ID);
    // std::thread domu2_server(vchan_server, DOMU2_ID);

    receiver.join();
    domu1_server.join();
    // domu2_server.join();

    return 0;
}

// check dom channel : xenstore-ls -f

// xenstore route
// /local/domain/0/data/vchan/control/
// /local/domain/2/data/vchan/control/
