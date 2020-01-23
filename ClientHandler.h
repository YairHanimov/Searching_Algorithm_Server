//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_CLIENTHANDLER_H
#define SEARCHING_ALGORITHM_SERVER_CLIENTHANDLER_H

class ClientHandler {
 public:
  virtual void handleClient(int inputStream, int outputStream){}
  virtual ClientHandler* clone() = 0;
};

#endif //SEARCHING_ALGORITHM_SERVER_CLIENTHANDLER_H
