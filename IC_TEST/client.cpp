#include "client.h"

#include <QDebug>
#include <thread>
#include <chrono>

Client::Client(QObject *parent): QThread(parent){
    vchanClient = libxenvchan_client_init(nullptr, 0, "control");
    if (!vchanClient){
        qDebug() << "Failed to create vchan client\n";
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

void Client::run(){
    if (!vchanClient){
        qDebug() << "Failed to create vchan client\n";
        return;
    }

    qDebug() << "Connected to dom0\n";

    while (true){
//        ControlData new_data{};
//        if (libxenvchan_wait(vchanClient))

        int read_len = libxenvchan_read(vchanClient, &control_data, sizeof(control_data));
        if (read_len == sizeof(ControlData)){
            processControlData();
        } else{
            qDebug() << "Failed to read data\n";
        }

//        speed_prev = control_data.speed;
//        control_data = new_data;
//        control_data.speed = EMA(new_data.speed, speed_prev);

//        emit speedReceived(control_data.speed);

//        qDebug() << "Received control data - "
//                 << " Speed : " << (control_data.speed)
//                 << " Distance : " << (control_data.distance)
//                 << " Gear : " << (control_data.gear_P ? "P" :
//                                   control_data.gear_D ? "D" :
//                                   control_data.gear_R ? "R" :
//                                   control_data.gear_N ? "N" : "Unknown");

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // set cycle with dom0
    }

//    libxenvchan_close(vchanClient);
//    vchanClient = nullptr;
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
}
