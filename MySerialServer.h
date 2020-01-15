//
// Created by yair on 12/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
#define SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H

#include "ClientHandler.h"
#include "server_side.h"
#include "CacheManager.h"

using namespace server_side;

template<class problem, class solution>
class MySerialServer : public Server {
private:
    int port = 0;
    ClientHandler client_handler;
    CacheManager<problem, solution> cache_manager;
public:
    MySerialServer(int port, const ClientHandler *ch, CacheManager<problem, solution> cm) {
        this->port = port;
        this->client_handler = ch;
        this->cache_manager = cm;
    }

    void open();
    void stop();

};


#endif //SEARCHING_ALGORITHM_SERVER_MYSERIALSERVER_H
