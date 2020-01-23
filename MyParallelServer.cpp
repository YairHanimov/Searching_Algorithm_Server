#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "chrono"
#include "MyParallelServer.h"
#include "thread"

#define TIMEOUT 15
using namespace std;

void MyParallelServer::open() {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        cerr << "Could not create a socket" << endl;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons((uint16_t) (this->port));

    //binding the socket to the requested address
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << address.sin_addr.s_addr << endl;
        cerr << address.sin_port << endl;
        cerr << "Could not bind the socket to an IP" << endl;
    }

    thread handler([this, socketfd, address] { start(socketfd, this->client_handler, address); });
    handler.join();
}

void MyParallelServer::start(int socketfd, ClientHandler *ch, sockaddr_in address) {
    for(int currentThread = 0; currentThread<this->threadNum ; currentThread++) {
        this->threadPool[currentThread].join();
    }
    this->stopServer = true;
}

void MyParallelServer::stop() {

}