#include "client.h"

#include <QDebug>
#include <thread>
#include <chrono>

Client::Client(QObject *parent): QThread(parent){
    const char *xs_path = "/local/domain/0/data/piracer/ic";
    vchanClient = libxenvchan_client_init(nullptr, 0, xs_path);
    if (!vchanClient){
        qDebug() << "Failed to create vchan client\n";
        perror("libxenvchan_client_init");
        return;
    } else{
        qDebug() << "Vchan client initialized success\n";
    }
}

Client::~Client(){
    if (vchanClient){
        libxenvchan_close(vchanClient);
    }
}

float Client::EMA(float new_val, float prev_val){
    return SMOOTHING_FACTOR * new_val + (1-SMOOTHING_FACTOR) * prev_val;
}

void Client::setMode(int mode){
    if (m_mode != mode){
        m_mode = mode;
        emit modeChanged();
    }
}

void Client::run(){
    qDebug() << "Client run() started\n";

    if (!vchanClient){
        qDebug() << "Failed to create vchan client\n";
        return;
    }

    qDebug() << "Connected to dom0\n";

    while (true){
        int read_len = libxenvchan_read(vchanClient, &control_data, sizeof(control_data));
        if (read_len == sizeof(ControlData)){
            processControlData();
        } else{
            qDebug() << "Failed to read control data\n";
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // set cycle with dom0
    }

    // std::thread controlDataThread([&]() {
    //     if (!vchanClient){
    //         qDebug() << "Failed to create vchan client\n";
    //         return;
    //     }
    //     qDebug() << "Connected to dom0\n";

    //     while (true) {
    //         int read_len = libxenvchan_read(vchanClient, &control_data, sizeof(control_data));
    //         if (read_len == sizeof(ControlData)) {
    //             processControlData();
    //         } else {
    //             qDebug() << "Failed to read control data";
    //         }
    //         // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //     }
    // });

    // std::thread modeReceiverThread([&]() {
    //     if (!vchanClient2){
    //         qDebug() << "Failed to create vchan client2\n";
    //         return;
    //     }
    //     qDebug() << "Connected to dom1\n";

    //     while (true) {
    //         int receivedMode = -1;
    //         if (libxenvchan_data_ready(vchanClient2) >= sizeof(int)) {
    //             int read_len = libxenvchan_read(vchanClient2, &receivedMode, sizeof(receivedMode));
    //             if (read_len == sizeof(int)) {
    //                 qDebug() << "Received mode from HU:" << receivedMode;
    //                 setMode(receivedMode);
    //             } else {
    //                 qDebug() << "Failed to read mode";
    //             }
    //         }
    //         std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //     }
    // });

    // controlDataThread.detach();
    // modeReceiverThread.detach();
}

void Client::processControlData(){
    float newSpeed = control_data.speed;
    float newSpeedFiltered = EMA(newSpeed, m_speedFiltered);

    int newGear = 0;
    if (control_data.gear_P == 1) newGear = 1;
    else if (control_data.gear_D == 1) newGear = 2;
    else if (control_data.gear_R == 1) newGear = 3;
    else if (control_data.gear_N == 1) newGear = 4;

    bool newIndicatorLeft = control_data.indicator_l;
    bool newIndicatorRight = control_data.indicator_r;

    int newMode = control_data.mode;

    if (m_speedFiltered != newSpeedFiltered){
        m_speedFiltered = newSpeedFiltered;
        emit speedReceived(m_speedFiltered);
    }

    if (m_gear != newGear){
        m_gear = newGear;
        emit gearChanged();
    }

    if (m_indicatorLeft != newIndicatorLeft){
        m_indicatorLeft = newIndicatorLeft;
        emit indicatorLeftChanged();
    }

    if (m_indicatorRight != newIndicatorRight){
        m_indicatorRight = newIndicatorRight;
        emit indicatorRightChanged();
    }

    if (m_mode != newMode){
        setMode(newMode);
    }
}
