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

    //thread handler(&MyParallelServer::start, this, socketfd, this->client_handler, address);
    //handler.detach();
    //this->start(socketfd, this->client_handler, address);
    thread handler([this, socketfd, address] { start(socketfd, this->client_handler, address); });
    handler.join();
}

void MyParallelServer::start(int socketfd, ClientHandler *ch, sockaddr_in address) {
    int i = 0;
    while (!stopServer) {
        if (listen(socketfd, 10) == -1) {
            cerr << "Error during listening command" << endl;
        }

        struct timeval tv;
        int timeout_in_seconds = TIMEOUT;
        tv.tv_sec = timeout_in_seconds;
        tv.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);

        //accepting a client
        socklen_t addrlen = sizeof(sockaddr_in);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, &addrlen);

        //this->client_handler->handleClient(client_socket, client_socket);
        cout<<"i am before threads"<<endl;
        //threadPool[i] = thread(&MyParallelServer::lunchThread, this, newC, client_socket, client_socket);
        thread *t = new thread(&ClientHandler::handleClient, this->client_handler->clone(), client_socket, client_socket);
        t->join();
        threadPool.push_back(t);
        //threadPool[i] = thread(&ClientHandler::handleClient, this->client_handler->clone(), client_socket, client_socket);
        i++;
        if(i == 10) {
            this->stop();
        }
    }
    //closing the listening socket
    close(socketfd);
}

void MyParallelServer::lunchThread(ClientHandler *c, int client_socket1, int client_socket2) {
    c->handleClient(client_socket1, client_socket2);
}
void MyParallelServer::stop() {
    for (auto & currentThread : threadPool) {
        currentThread->join();
    }
    this->stopServer = true;
}