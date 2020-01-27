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
        // instalization
        char buffer[1024] = {0};
        bool inputEnd=false;
        string newLine;
        string all;
        while (true) {
            // reading from the buffer until we see "end"
            bzero(buffer, 1024);
            int readind= read(inputStream, buffer, 1024);
            int i = 0;
            newLine="";
            while (buffer[i] != '\0') {
                newLine+=buffer[i];
                i++;
            }

            if (newLine.size() == 0) {
                continue;
            }

            if ((newLine.compare("end\n") == 0) || (newLine.compare("end") == 0)|| (newLine.compare("end\r\n") == 0) )  {
                break;
            } else {
                all +=newLine;
            }
        }


        auto solu = this->cache_manager->get(all);
        const char *myResult;
        int sendBack;
        if (solu == NULL) {
            // calling to oa because we dont have solution
            auto *object_adapter = new OA<string, string>();
            string afterfix = "";
            cout << "New problem. Trying to solve..." << endl;
            afterfix = object_adapter->solve(all);
            this->cache_manager->insert(all, afterfix);
            myResult = afterfix.c_str();
            sendBack = send(outputStream, myResult, strlen(myResult), 0);
        } else {
            // we have the solution in the disk
            string sol = *solu;
            cout << "Printing solution:" << endl;
            cout << sol << endl;
            myResult = sol.c_str();
            sendBack = send(outputStream, myResult, strlen(myResult), 0);
        }
        close(outputStream);
    }

    //clone current object
    MyClientHandler *clone() override {
        auto *newHandler = new MyClientHandler(this->cache_manager);
        return newHandler;
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_MYCLIENTHANDLER_H