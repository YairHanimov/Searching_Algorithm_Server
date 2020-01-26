////
//// Created by eyal on 12.1.2020.
////
//
//#include <stdio.h>
//#include "MyTestClientHandler.h"
//#include "StringReverser.h"
//#include <iostream>
//#include <unistd.h>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//void MyTestClientHandler::handleClient(int inputStream, int outputStream) {
//    char buffer[1024] = {0};
//    vector<string> line;
//    while (true) {
//        buffer[1024] = {0};
//
//        ssize_t valread = read(inputStream, buffer, 1024);
//        if (strcmp(buffer, "end") == 0) {
//            break;
//        }
//        cout << buffer << endl;
//
//        auto solu = this->cache_manager->get(buffer);
//        if (solu==NULL){
//            StringReverser *rev = new StringReverser();
//             string afterfix="";
//             afterfix+= rev->solve(buffer);
//             this->cache_manager->insert(buffer,afterfix);
//        }
//        else
//            cout<<solu<<endl;
//
//
//        char *token = strtok(buffer, "\n");
//        while (token != NULL) {
//            cout << " my token" << endl;
//            cout << token << endl;
//            line.push_back(token);
//
//            token = strtok(NULL, "\n");
//
//        }
//    }
//}