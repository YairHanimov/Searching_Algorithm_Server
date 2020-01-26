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
//        char buffer[20000] = {0};
//        //sleep(0.5);
//        while (true) {
//            ssize_t valread = read(inputStream, buffer, 1024);
//            if (strcmp(buffer, "end") == 0) {
//                cout<<"in end"<<endl;
//                break;
//            }
//            //sleep(0.5);
//
//            string testbuffer = buffer;
//            auto solu = this->cache_manager->get(testbuffer);
//            if (solu == NULL) {
//                // calling to oa because we dont have solution
//                auto *object_adapter = new OA<string, string>();
//                string afterfix = "";
//                afterfix = object_adapter->solve(testbuffer);
////                StringReverser *rev = new StringReverser();
////                string afterfix = "";
////                afterfix += rev->solve(buffer);
////                cout << "reverse are comiing";
////                cout << afterfix << endl;
//
//                this->cache_manager->insert(testbuffer, afterfix);
//            } else {
//                string s = *solu;
//                cout << "ia am going print" << endl;
//                cout << s << endl;
//
//            }
//        }


        char buffer[1024] = {0};
        bool inputEnd=false;
        string newLine;
        string all;
        while (true) {
            bzero(buffer, 1024);


            int valread = read(inputStream, buffer, 1024);
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
                const char *checkSent = "";
                int is_send = send(outputStream, checkSent, strlen(checkSent), 0);

            }

        }


        auto solu = this->cache_manager->get(all);
        const char *myResult;
        int sendBack;
        if (solu == NULL) {
            // calling to oa because we dont have solution
            auto *object_adapter = new OA<string, string>();
            string afterfix = "";
            cout << "i am before solve" << endl;
            afterfix = object_adapter->solve(all);
            this->cache_manager->insert(all, afterfix);
            myResult = afterfix.c_str();
            sendBack = send(outputStream, myResult, strlen(myResult), 0);
        } else {
            string sol = *solu;
            cout << "ia am going print" << endl;
            cout << sol << endl;
            myResult = sol.c_str();
            sendBack = send(outputStream, myResult, strlen(myResult), 0);
        }
        close(outputStream);
    }

    MyClientHandler *clone() override {
        auto *newHandler = new MyClientHandler(this->cache_manager);
        return newHandler;
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_MYCLIENTHANDLER_H
