//
// Created by yair on 12/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYPARALLELSERVER_H
#define SEARCHING_ALGORITHM_SERVER_MYPARALLELSERVER_H

#include <sys/socket.h>
#include "MySerialServer.h"
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "chrono"
#include "server_side.h"
#include "thread"

using namespace server_side;

#define DEFAULT_PORT 5600
#define DEFAULT_THREAD_NUM 10

#include "list"
using namespace std;

class MyParallelServer : public Server {

private:
    int port = DEFAULT_PORT;
    static const int threadNum = DEFAULT_THREAD_NUM;
    int currentThreadNum = 0;
    vector<thread*> threadPool;
    bool stopServer;
    ClientHandler *client_handler;
public:
    explicit MyParallelServer(int input_port, ClientHandler *ch) {
        this->port = input_port;
        this->client_handler = ch;
        this->stopServer = false;
    }

    MyParallelServer(ClientHandler *ch) {
        this->client_handler = ch;
        this->stopServer = false;
    }

    void open() override;

    void stop() override;

    void start(int socketfd, ClientHandler *pHandler, sockaddr_in in);
};

#endif //SEARCHING_ALGORITHM_SERVER_MYPARALLELSERVER_H
