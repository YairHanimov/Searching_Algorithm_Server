//
// Created by eyal on 12.1.2020.
//

#include <stdio.h>
#include "MyTestClientHandler.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>

using namespace std;

template<class problem, class solution>
void MyTestClientHandler<problem, solution>::handleClient(int inputStream, int outputStream) {
    char buffer[1024] = {0};
    vector<string> line;
    while (true) {
        buffer[1024] = {0};

        ssize_t valread = read(inputStream, buffer, 1024);
        if (strcmp(buffer, "end") == 0) {
            break;
        }
        cout << buffer << endl;

//        char *token = strtok(buffer, "\n");
//        while (token != NULL) {
//            cout << " my token" << endl;
//            cout << token << endl;
//            line.push_back(token);
//
//            token = strtok(NULL, "\n");
//
//        }
    }
}