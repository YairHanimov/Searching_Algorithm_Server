//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYCLIENTHANDLER_H
#define SEARCHING_ALGORITHM_SERVER_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include <iostream>
#include <unistd.h>
#include "StringReverser.h"
#include "Solver.h"
#include "OA.h"

using namespace std;

template<class problem, class solution>
class MyClientHandler : public ClientHandler {
public:
    CacheManager<problem, solution> *cache_manager;
    int stream;
    MyClientHandler(CacheManager<problem, solution> *cm) {
        this->cache_manager = cm;
    }

    void handleClient(int inputStream, int outputStream) override {
        char buffer[1024] = {0};
        vector<string> line;
        while (true) {
            buffer[1024] = {0};
            ssize_t valread = read(inputStream, buffer, 1024);
            if (strcmp(buffer, "end") == 0) {
                break;
            }
            auto solu = this->cache_manager->get(buffer);
            if (solu == NULL) {
                // calling to oa because we dont have solution
                auto *object_adapter = new OA<string, string>();
                string afterfix = "";
                afterfix = object_adapter->solve(buffer);
                this->cache_manager->insert(buffer, afterfix);
            } else {
                string s = *solu;
                cout << "ia am going print" << endl;
                cout << s << endl;
            }
        }
    }

    MyClientHandler *clone() override {
        auto *newHandler = new MyClientHandler(this->cache_manager);
        return newHandler;
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_MYCLIENTHANDLER_H
