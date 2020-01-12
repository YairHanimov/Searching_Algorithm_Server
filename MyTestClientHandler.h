//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H
#define SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler{
 public:
  void handleClient(int inputStream, int outputStream) override;
};

#endif //SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H
