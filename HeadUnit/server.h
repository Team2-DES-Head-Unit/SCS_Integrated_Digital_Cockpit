#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <cstring>
#include <QObject>
#include <QDebug>
#include <QThread>

// extern "C"{
//     #include <libxenvchan.h>
// }
#include <libxenvchan_wrapper.h>

class Server : public QObject{
    Q_OBJECT

private:
    struct libxenvchan *vchanServer = nullptr;

public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

    void start();

    Q_INVOKABLE void sendModeToIC(int mode);
};

#endif // SERVER_H
