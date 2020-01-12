//
// Created by yair on 12/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYPARALLELSERVER_H
#define SEARCHING_ALGORITHM_SERVER_MYPARALLELSERVER_H

#include "server_side.h"
using namespace server_side;

class MyParallelServer : public Server{

private:
    int port;
    ClientHandler client_handler;
 public:
  MyParallelServer() {

  }
};

#endif //SEARCHING_ALGORITHM_SERVER_MYPARALLELSERVER_H
