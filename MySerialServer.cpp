#include <sys/socket.h>
#include "MySerialServer.h"
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "chrono"

#define TIMEOUT 15
using namespace std;

void MySerialServer::open(int port, MyTestClientHandler c) {
  this->port = port;
  this->client_handler = c;
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

  //waiting for the simulator to approach the server to make a connection
  if (listen(socketfd, 1) == -1) {
    cerr << "Error during listening command" << endl;
  }
  struct timeval tv;
  int timeout_in_seconds = TIMEOUT;
  tv.tv_sec = timeout_in_seconds;
  tv.tv_usec = 0;
  setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);

  //accepting a client
  bool serialListening = true;
  socklen_t addrlen = sizeof(sockaddr_in);
  while (serialListening) {
    int client_socket = -1;
    client_socket = accept(socketfd, (struct sockaddr *) &address, &addrlen);

    if (client_socket < 0) {
      serialListening = false;
    }

    this->client_handler.handleClient(client_socket, client_socket);
  }
  //closing the listening socket
  close(socketfd);

}
void MySerialServer::stop() {

}

#include "MySerialServer.h"
