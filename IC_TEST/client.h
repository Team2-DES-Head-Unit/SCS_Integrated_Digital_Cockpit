#ifndef CLIENT_H
#define CLIENT_H

#include <QThread>
#include <QObject>
// #include <libxenvchan.h>

extern "C"{
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
    uint8_t mode;
};

class Client: public QThread
{
    Q_OBJECT
    Q_PROPERTY(float speedKmh READ getSpeedKmh NOTIFY speedReceived)
    Q_PROPERTY(int gear READ getGear NOTIFY gearChanged)
    Q_PROPERTY(bool indicatorLeft READ getIndicatorLeft NOTIFY indicatorLeftChanged)
    Q_PROPERTY(bool indicatorRight READ getIndicatorRight NOTIFY indicatorRightChanged)
    Q_PROPERTY(int mode READ mode WRITE setMode NOTIFY modeChanged)

private:
    struct libxenvchan *vchanClient = nullptr; // server : dom0
    ControlData control_data;

    float speed_prev = 0;
    const float SMOOTHING_FACTOR = 0.4;

    float m_speedFiltered = 0.0f;
    int m_gear = 0;
    bool m_indicatorLeft = false;
    bool m_indicatorRight = false;
    int m_mode = 0;

    void processControlData();

public:
//    static const int SUCCEDED = 0;
//    static const int FAILED = -1;
//    const float SMOOTHING_FACTOR = 0.4;

    explicit Client(QObject *parent = nullptr);
    ~Client();

    float getSpeedKmh() const{ return m_speedFiltered; }
    int getGear() const { return m_gear; }
    bool getIndicatorLeft() const { return m_indicatorLeft; }
    bool getIndicatorRight() const { return m_indicatorRight; }
    int mode() const { return m_mode; }

    float EMA(float new_val, float prev_val);

    void setMode(int mode);

protected:
    void run() override;

signals:
    void speedReceived(float speedKmh);
    void gearChanged();
    void indicatorLeftChanged();
    void indicatorRightChanged();
    void modeChanged();
};

#endif // CLIENT_H
