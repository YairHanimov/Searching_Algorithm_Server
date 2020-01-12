//
// Created by yair on 12/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
#define SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "
class MySerialServer : public Server {
private:
    int port;
    ClientHandler c;
public:
    MySerialServer() {

    }

};


#endif //SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
