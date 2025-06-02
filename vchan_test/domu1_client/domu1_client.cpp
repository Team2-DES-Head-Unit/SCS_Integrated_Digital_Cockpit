#include <iostream>
#include <cstring>

extern "C" {
    #include <libxenvchan.h>
}

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

int main(){
    struct libxenvchan *client = libxenvchan_client_init(nullptr, 0, "control");
    if (!client){
        std::cerr << "Failed to create vchan client" << std::endl;
        return 1;
    }

    std::cout << "Connected to dom0" << std::endl;

    // char buffer[128];
    while(true){
        ControlData data;
        int read_len = libxenvchan_read(client, &data, sizeof(data));
        // if (read_len > 0){
        //     buffer[len] = '\0'; // null-terminate the string
        //     std::cout << "Received : " << buffer << std::endl;
        // } 
        if (read_len == sizeof(data)){
            std::cout << "Received control data - "
                      << " Gear : " << (data.gear_P ? "P" : (data.gear_D ? "D" : (data.gear_R ? "R" : "N")))
                      << std::endl;
        } else {
            std::cerr << "Failed to read data or unexpected data size" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // wait before next read
    }
    libxenvchan_close(client);
    return 0;
}