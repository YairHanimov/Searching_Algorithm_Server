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

void MyTestClientHandler::handleClient(int inputStream, int outputStream) {
    char buffer[1024] = {0};
    vector<string> line;
    while (true) {

        ssize_t valread = read(inputStream, buffer, 1024);
        cout << buffer << endl;
        char *token = strtok(buffer, "\n");
        while (token != NULL) {
            line.push_back(token);
            token = strtok(NULL, "\n");
        }
    }
}