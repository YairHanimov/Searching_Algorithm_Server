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
    Solver<problem, solution> *sol;

    MyClientHandler(CacheManager<problem, solution> *cm, Solver<problem,solution> *s) {
        this->cache_manager = cm;
        this->sol = s;
    }

    virtual void handleClient(int inputStream, int outputStream) {
        char buffer[1024] = {0};
        vector<string> line;
        while (true) {
            buffer[1024] = {0};

            ssize_t valread = read(inputStream, buffer, 1024);
            if (strcmp(buffer, "end") == 0) {
                break;
            }

            string line1 = "1,2,3,4";
            string line2 = "5,6,7,8";
            string line3 = "9,10,11,12";
            string line4 = "13,14,15,16";
            string enter = "0,0\n";
            string exit = "3,3\n";
            string end = "end\n";
            string testbuffer ="";
            testbuffer+=line1+"\n"+line2+"\n"+line3+"\n"+line4+"\n"+enter+exit+end;

            auto solu = this->cache_manager->get(testbuffer);
            if (solu == NULL) {
                // calling to oa because we dont have solution
                auto *object_adapter = new OA<string,string>();
                string afterfix = "";
                afterfix=object_adapter->solve(testbuffer);
//                StringReverser *rev = new StringReverser();
//                string afterfix = "";
//                afterfix += rev->solve(buffer);
//                cout << "reverse are comiing";
//                cout << afterfix << endl;

                this->cache_manager->insert(testbuffer, afterfix);
            } else {
                string s = *solu;
                cout << "i am going print" << endl;
                cout<<s<<endl;
            }


        }
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_MYCLIENTHANDLER_H
