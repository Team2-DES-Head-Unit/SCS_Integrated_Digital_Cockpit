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

extern "C"{
    #include <libxenvchan.h>
}

class Server : public QObject{
    Q_OBJECT

private:
    struct libxenvchan *vchanServer = nullptr;

public:
    explicit Server(QObject *parent = nullptr) : QObject(parent), vchanServer(nullptr){
        // const char *huxs_path = "/local/domain/1/data/hu"; // hu domu id : 1
        // vchanServer = libxenvchan_server_init(nullptr, 2, huxs_path, 0, 0); // ic domu id : 2
        // if (!vchanServer){
        //     qDebug() << "Failed to create vchan server - HU\n";
        //     return;
        // } else{
        //     qDebug() << "HU - IC Vchan server init success\n";
        // }
    }

    ~Server(){
        if (vchanServer){
            libxenvchan_close(vchanServer);
        }
    }

    void start(){
        const char *huxs_path = "/local/domain/1/data/hu"; // hu domu id : 1
        vchanServer = libxenvchan_server_init(nullptr, 2, huxs_path, 0, 0); // ic domu id : 2
        if (!vchanServer){
            qDebug() << "Failed to create vchan server - HU\n";
            return;
        } else{
            qDebug() << "HU - IC Vchan server init success\n";
        }
    }

    Q_INVOKABLE void sendModeToIC(int mode){
        int data = mode;

        int bf_size = libxenvchan_buffer_space(vchanServer);
        if (bf_size < sizeof(data)) {
            qDebug() << "Not enough space in vchan buffer.";
            return;
        }

        int send_byte = libxenvchan_write(vchanServer, &data, sizeof(data));
        if (send_byte <= 0){
            qDebug() << "Failed to write changed mode type\n";
        } 
        qDebug() << "Sent mode:" << mode;
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
};

#endif // SERVER_H
