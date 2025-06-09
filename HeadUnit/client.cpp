#include "client.h"

#include <QDebug>
#include <thread>
#include <chrono>

Client::Client(QObject *parent): QThread(parent){
    const char *xs_path = "/local/domain/0/data/piracer/hu";
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

void Client::sendModeToIC(uint8_t mode){
    if (!vchanClient){
        qDebug() << "Failed to create vchan client\n";
        perror("libxenvchan_client_init");
    }

    int written = libxenvchan_write(vchanClient, &mode, sizeof(mode));
    if (written <= 0) {
        qDebug() << "Failed to write mode to dom0";
    } else {
        qDebug() << "Sent mode to dom0: " << mode;
    }
}

void Client::run(){
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
            qDebug() << "Failed to read data\n";
        }

        // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // set cycle with dom0
    }
}

void Client::processControlData(){
    float newSpeed = control_data.speed;
    float newSpeedFiltered = EMA(newSpeed, m_speedFiltered);
    float newDistance = control_data.distance;

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

    if (m_distance != newDistance){
        m_distance = newDistance;
        emit distanceReceived(m_distance);
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
