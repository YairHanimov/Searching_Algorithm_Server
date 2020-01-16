//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H
#define SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>
#include "StringReverser.h"
#include "Solver.h"

using namespace std;

template<class problem, class solution>
class MyTestClientHandler : public ClientHandler {
public:
    CacheManager<problem, solution> *cache_manager;
    Solver<problem, solution> *sol;

    MyTestClientHandler(CacheManager<problem, solution> *cm, Solver<problem,solution> *s) {
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


            auto solu = this->cache_manager->get(buffer);
            if (solu == NULL) {
                StringReverser *rev = new StringReverser();
                string afterfix = "";
                afterfix += rev->solve(buffer);
                cout << "reverse are comiing";
                cout << afterfix << endl;
                this->cache_manager->insert(buffer, afterfix);
            } else {
                string s = *solu;
                cout << "i am going print" << endl;
                cout<<s<<endl;
            }

            char *token = strtok(buffer, "\n");
            while (token != NULL) {
                cout << " my token" << endl;
                //   cout << token << endl;
                line.push_back(token);

                token = strtok(NULL, "\n");

            }
        }
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_MYTESTCLIENTHANDLER_H
