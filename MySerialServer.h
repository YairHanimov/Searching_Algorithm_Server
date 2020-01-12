//
// Created by yair on 12/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
#define SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "server_side.h"

using namespace server_side;

class MySerialServer : public Server {
private:
    int port;
    ClientHandler client_handler;
public:
    MySerialServer() {

    }

    void  open(int , ClientHandler );
    void stop();

};


#endif //SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
