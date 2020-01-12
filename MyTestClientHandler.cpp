//
// Created by eyal on 12.1.2020.
//

#include <stdio.h>
#include "MyTestClientHandler.h"
#include <sys/socket.h>
#include "MySerialServer.h"
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "chrono"
void MyTestClientHandler::handleClient(int inputStream, int outputStream) {
    char buffer[1024] = {0};
    ssize_t valread = read(inputStream, buffer, 1024);

}