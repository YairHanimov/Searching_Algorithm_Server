//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_SERVER_SIDE_H
#define SEARCHING_ALGORITHM_SERVER_SERVER_SIDE_H

#include "ClientHandler.h"

namespace server_side {

class Server {

public:
  virtual void open(){}
  virtual void stop(){}
};
}
#endif //SEARCHING_ALGORITHM_SERVER_SERVER_SIDE_H
