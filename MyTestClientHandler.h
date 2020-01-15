//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H
#define SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"

//template<class problem, class solution>
class MyTestClientHandler : public ClientHandler {
public:
  //  CacheManager<problem, solution> *cache_manager;
//    MyTestClientHandler(CacheManager<problem, solution> *cm) {
//        this->cache_manager = cm;
//    }
    virtual void handleClient(int inputStream, int outputStream);
};

#endif //SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H
