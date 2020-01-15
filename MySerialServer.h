//
// Created by yair on 12/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
#define SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "server_side.h"
#include "CacheManager.h"
#include "MyTestClientHandler.h"

using namespace server_side;

class MySerialServer : public Server {
private:
    int port = 0;
    ClientHandler *client_handler;
public:
    MySerialServer(int port, ClientHandler *ch) {
        this->port = port;
        this->client_handler = ch;
    }

    void open() override;
    void stop() override;

};


#endif //SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
