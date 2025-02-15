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

#define DEFAULT_PORT 5600
class MySerialServer : public Server {
private:
    int port = DEFAULT_PORT;
    ClientHandler *client_handler;
public:
    MySerialServer(int port, ClientHandler *ch) {
        this->port = port;
        this->client_handler = ch;
    }
    MySerialServer(ClientHandler *ch) {
        this->client_handler = ch;
    }

    void open() override;
    void stop() override;

};


#endif //SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
