#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <cstring>
#include <QObject>
#include <QDebug>
#include <QThread>
// #include <libxenvchan.h>
// extern "C"{
//     #include <libxenvchan.h>
// }
#include <libxenvchan_wrapper.h>

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

extern struct ControlData controlData;

class Client : public QThread {
    Q_OBJECT
    Q_PROPERTY(float speedKmh READ getSpeedKmh NOTIFY speedReceived)
    Q_PROPERTY(float distanceCm READ getDistance NOTIFY distanceReceived)
    Q_PROPERTY(int gear READ getGear NOTIFY gearChanged)
    Q_PROPERTY(bool indicatorLeft READ getIndicatorLeft NOTIFY indicatorLeftChanged)
    Q_PROPERTY(bool indicatorRight READ getIndicatorRight NOTIFY indicatorRightChanged)
//    Q_PROPERTY(bool battery READ battery NOTIFY batteryChanged)

private:
    struct libxenvchan *vchanClient = nullptr;
    ControlData control_data;

    float speed_prev = 0;
    const float SMOOTHING_FACTOR = 0.4;

    float m_speedFiltered = 0.0f;
    float m_distance = 0.0f;
    int m_gear;
    bool m_indicatorLeft;
    bool m_indicatorRight;
//    int m_battery;

    void processControlData();

public:
    explicit Client(QObject *parent = nullptr);
    ~Client();

    float getSpeedKmh() const{ return m_speedFiltered; }
    float getDistance() const{ return m_distance; }
    int getGear() const { return m_gear; }
    bool getIndicatorLeft() const { return m_indicatorLeft; }
    bool getIndicatorRight() const { return m_indicatorRight; }
//    int battery() const { return m_battery; }

    float EMA(float new_val, float prev_val);

protected:
    void run() override;

signals:
    void speedReceived(float speedKmh);
    void distanceReceived(float distanceCm);
    void gearChanged();
    void indicatorLeftChanged();
    void indicatorRightChanged();
//    void batteryChanged();

};

#endif // CLIENT_H
