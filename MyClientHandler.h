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

    MyClientHandler(CacheManager<problem, solution> *cm, Solver<problem, solution> *s) {
        this->cache_manager = cm;
        this->sol = s;
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

//            string line1 = "1,2,3,100";
//            string line2 = "5,6,7,8";
//            string line3 = "9,10,11,12";
//            string line4 = "13,14,15,16";
//            string enter = "0,0\n";
//            string exit = "3,3\n";
//            string end = "end\n";
//            string testbuffer ="";
//            testbuffer+=line1+"\n"+line2+"\n"+line3+"\n"+line4+"\n"+enter+exit+end;
//            string testbuffer = "8,2,8,6,8,2,12,2,4,1,9,9,5,12,1,1,1,2,7,3,1,6,9,3,9,7,7,9,5,6,4,5,1,6,-1,1,7\n"
//                                "4,12,2,3,2,5,2,1,12,2,4,5,4,3,3,4,12,2,3,9,6,9,1,6,7,7,5,8,7,2,-1,3,2,5,-1,9,2\n"
//                                "1, 5, 8, 9, 2, 1, 2, 4, 7, 8, 2, 9, 8, 4, 2, 2,12, 8, 8, 2, 3, 3, 1, 5,12,-1, 2, 7, 1, 4,-1,-1,-1, 2,-1, 5, 6\n"
//                                "8, 6, 2, 4,12, 8, 9, 9, 7, 1, 2, 8, 8, 2, 4, 2, 1, 7, 6, 8, 3,-1, 8, 1, 8, 6, 1, 3, 3, 2, 7, 3, 4, 2, 9,12, 2\n"
//                                "7, 6, 2,12, 7, 8, 1,-1, 5, 8, 8, 1, 1, 5, 8, 9, 9, 1, 8, 5, 1, 8, 4, 5, 4, 5, 8, 7, 6, 6, 8, 2, 2, 8, 8, 8, 8\n"
//                                "9, 3, 2, 3, 5,12,-1, 9, 2, 8, 3, 8, 2,12,12, 7, 1, 8, 4, 2,12, 5, 4, 7, 4, 4, 6,12, 9, 2, 3, 5,12, 2, 2, 3, 5\n"
//                                "12, 5, 1, 7, 5,12, 6, 6, 6, 5, 8, 9, 4, 3, 9, 2,12, 4, 9, 5, 3,12, 3, 9, 3, 4,-1, 8, 5, 2,12, 5, 2, 3, 7, 6,-1\n"
//                                " 1,12, 2, 9, 9, 1, 2, 2,-1, 2, 6,12, 1,12,12, 2, 7, 5, 2, 7, 7, 6, 9, 2, 3, 2, 4, 9,-1, 5, 7,-1, 9, 8, 6, 3, 4\n"
//                                "12, 2, 1, 2, 6,12, 2, 6,-1,-1, 3, 9, 9, 8, 3, 7, 4, 3, 4, 5,-1, 9, 3, 5,12, 2, 3,-1,12, 2, 2, 2, 7, 8,-1,12, 2\n"
//                                " 7, 4, 8, 2, 8, 7,-1, 3,-1, 2,-1, 7, 9, 6, 7, 6, 1,12, 6, 2, 5, 8, 1, 2, 8, 3, 2,12, 7,12, 1, 2, 6, 9, 7, 3, 8\n"
//                                " 6, 2, 4, 7, 7,12, 8, 2, 1, 6, 2, 6, 4, 6, 6, 7, 5, 5, 8, 2,12, 2, 6, 8,12, 8,12, 9, 9, 2, 2, 2, 9, 6, 5, 4, 2\n"
//                                " 7, 2, 9, 4, 7, 4, 5, 8, 2, 2, 4, 3, 6, 1, 4, 7, 4, 9,-1, 5,12, 3, 4, 9, 7,12, 3, 5, 2, 9, 7, 2,-1, 5,12, 7, 1\n"
//                                " 6, 6, 8, 2,12, 4,-1, 4,-1, 2, 9, 6, 5, 7, 2, 4, 9,12, 4, 9, 2, 9, 2, 6, 7, 1,12, 5, 6, 6, 5,12, 4, 5, 7, 6, 8\n"
//                                " 3, 9, 1, 4, 8, 2,-1, 2,-1, 7, 8, 3, 6, 6, 9, 4, 6,-1, 4,-1, 1, 4, 5, 9, 2, 2, 1, 9, 3, 7, 2, 1,12, 5, 6,-1, 9\n"
//                                "12, 8, 9, 1,12, 7, 2,12, 9,12,12, 1, 9, 3, 7, 5, 9, 3, 8, 6, 6, 7, 1, 1, 5, 6, 2, 7, 2, 3, 4, 9, 9, 9,12, 2, 8\n"
//                                "12, 2, 8, 5,-1, 2, 5, 8, 7, 2, 5, 1, 3, 2, 4, 3, 9, 5, 9, 7, 7, 2,-1, 2, 8, 4, 1, 5, 9, 6, 2, 4, 2, 9, 1,-1, 2\n"
//                                " 4, 4, 5,12, 2, 5, 2, 3, 2, 2, 2, 4, 5, 3,12, 9, 3, 6, 2, 9, 9, 1, 4, 3, 2,12, 3, 1, 8, 6, 7, 4, 6, 7, 5, 1, 8\n"
//                                " 4,-1, 9, 7, 5, 5, 3,12, 8, 3, 3, 9, 5, 6, 1,12, 7, 4, 9, 9, 5, 9, 8, 9, 9, 1, 6, 9, 7, 5, 3, 5, 4, 6, 3, 2, 1\n"
//                                " 9, 2, 1, 5, 1, 3, 8, 2, 1, 2, 5, 2, 9, 9, 3, 4, 2, 2, 2,12, 7, 2,12, 3, 7, 2, 8, 9, 2, 1, 2, 2, 2, 3, 4,12, 3\n"
//                                " 6, 6, 1,-1,12, 7, 1, 5, 2, 3, 5, 8,12, 7, 3, 2, 6, 8, 5, 1,12, 2, 6, 6, 8, 2, 7,-1, 2, 7, 9, 5, 5, 7, 1, 5, 4\n"
//                                " 3, 6, 4,12, 7, 8, 2, 9, 8, 3, 4, 3, 8, 7, 6, 6, 2, 7, 9, 6, 6, 2, 2, 6, 5, 9, 2, 3, 3, 3,12, 7,12, 6, 7, 2, 9\n"
//                                "12, 1, 2,-1, 7, 2, 5,12, 2, 8, 4, 7, 8, 7, 7, 5, 2, 5, 7, 4, 2, 4, 3,12, 6, 8, 5, 2, 1, 4, 9, 2, 1, 4, 2, 2, 2\n"
//                                "12, 4, 9,12, 9,12, 9,12, 7, 9, 2, 1, 6, 5, 3, 2, 6, 4, 7, 9,12, 4, 4, 9, 8, 1, 7, 8, 2, 2, 9, 3, 8, 5, 3, 7, 6\n"
//                                " 7, 4, 6, 2, 7, 7, 8, 6, 8, 9, 1, 2, 9, 3, 4, 9, 2, 8,12, 1, 2, 5, 9, 8, 7, 9, 3, 3,12, 7, 9, 8, 3, 2,12, 3, 6\n"
//                                " 9, 2, 1, 8, 4, 8, 1, 8, 6, 2, 3, 9, 1, 7, 3, 8, 5, 8, 5, 4, 4,12, 5, 2, 9, 2, 1, 9, 2, 6, 8, 4, 4,-1,-1,-1,12\n"
//                                " 7, 7, 2, 8, 4, 4, 1, 9, 8, 2, 9, 8,12, 5, 5, 2, 8, 1, 5, 9, 9,12, 6, 5, 9, 8, 1, 4, 4, 7, 6,12, 4, 9, 1, 8, 2\n"
//                                " 1, 6, 7, 2, 8, 7, 6,12, 1, 2, 9, 5,12, 7, 6, 4, 9, 2, 2, 5, 1, 9, 2, 1, 6, 8, 3, 2, 8, 1, 2, 6, 9, 8, 3,-1, 2\n"
//                                " 5, 5, 7,12, 1, 8, 4, 4, 2,12,12, 1, 1, 2, 8, 4, 8, 2, 6, 8, 3, 8, 5, 5, 3, 8,12, 8, 5,12, 1,12, 2, 5, 2,-1, 6\n"
//                                " 9, 2, 8, 1, 3, 5, 6, 2, 7, 9, 2, 1, 6, 8, 1, 2, 1, 5, 2, 2,12, 2, 4, 9, 2, 2, 4, 7, 4, 3, 6, 9, 6, 5,12, 2, 3\n"
//                                " 1, 7, 2, 2, 5, 6,12, 6, 6,12,12, 2, 1, 2, 2, 7, 1, 1, 8, 3, 5, 2,12, 1, 8, 2, 6, 3, 2, 9, 3, 2, 4, 9, 8, 5, 3\n"
//                                " 1, 3, 2, 1, 1, 6, 3,-1, 2, 4, 8, 7, 3, 4, 7, 6, 1, 9, 7, 2,12, 4, 6, 5, 7, 8, 2,12, 1, 2, 6, 7, 8, 2, 3,12, 9\n"
//                                "3, 6, 4, 9, 2,12, 9, 8, 2, 7, 6, 6, 8, 3, 7, 9, 3, 7, 2, 2, 3, 2, 4, 5, 8, 7, 2,12,12, 4,12, 2,12,-1, 6,-1, 2\n"
//                                "6, 4, 4,12, 8, 3, 2, 7, 3, 8, 4, 7, 3, 1, 5, 6, 2, 2, 2, 6, 2, 1, 4, 3, 1, 4, 2, 5, 7, 1, 6, 5,12, 7, 5,-1, 3\n"
//                                "4, 8, 2, 2,12, 9, 3, 3, 8, 7, 7, 8,12, 6,12, 2, 4,12, 2,12, 7, 8, 7, 1, 9, 5,12, 4, 2, 2, 9, 7, 1, 8, 3, 8, 9\n"
//                                "2, 2, 5, 1, 7, 1, 8, 2,12, 3,12, 5, 7, 9,12,12,12, 2, 4, 4, 2,12, 2, 2, 1, 6, 9,12, 7, 4, 6,12, 8, 4, 8, 2,12\n"
//                                "3, 1, 2, 8, 1, 4, 7, 9, 3, 7, 3, 6, 6, 6, 3, 9, 9, 3, 9, 3, 3, 7, 5,12, 2, 8, 2, 2, 5, 4, 9, 8, 5, 3, 2, 6, 4\n"
//                                "12, 1, 9, 5, 9, 2, 6,12, 3, 4,12,-1,12, 7, 9, 2, 1, 2, 2, 4, 6,12, 2, 2, 2, 3, 4, 1, 4, 4, 2, 4,12, 6, 2, 5, 6\n"
//                                "0,0\n"
//                                "36,36\n"
//                                "end";

            string testbuffer = "0,7,200,200,200,200,1,4,-1,5\n"
                                "0,0,0,1,-1,1,3,8,9,8\n"
                                "0,4,0,9,6,2,8,4,5,2\n"
                                "0,0,-1,0,7,7,4,8,2,1\n"
                                "0,6,3,0,0,5,2,3,9,9,1\n"
                                "0,3,-1,-1,0,6,-1,4,8,4\n"
                                "0,-1,-1,-1,0,2,-1,5,7,2\n"
                                "0,4,-1,-1,5,0,2,2,3,3\n"
                                "0,6,-1,-1,1,8,0,3,3,7\n"
                                "0,0,0,100,7,7,0,0,0,5\n"
                                "0,0\n"
                                "5,5\n"
                                "end ";
//            string testbuffer ="1,2,3,-1\n"
//                               "5,6,7,8\n"
//                               "9,10,11,12\n"
//                               "13,14,15,16\n"
//                               "0,0\n"
//                               "3,3\n"
//                               "end";
            auto solu = this->cache_manager->get(testbuffer);
            if (solu == NULL) {
                // calling to oa because we dont have solution
                auto *object_adapter = new OA<string, string>();
                string afterfix = "";
                afterfix = object_adapter->solve(testbuffer);
//                StringReverser *rev = new StringReverser();
//                string afterfix = "";
//                afterfix += rev->solve(buffer);
//                cout << "reverse are comiing";
//                cout << afterfix << endl;

                this->cache_manager->insert(testbuffer, afterfix);
            } else {
                string s = *solu;
                cout << "ia am going print" << endl;
                cout << s << endl;

            }


        }
    }

    MyClientHandler *clone() override {
        auto *newHandler = new MyClientHandler(this->cache_manager, this->sol->clone());
        return newHandler;
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_MYCLIENTHANDLER_H
