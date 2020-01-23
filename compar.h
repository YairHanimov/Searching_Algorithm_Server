//
// Created by yair on 20/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_COMPAR_H
#define SEARCHING_ALGORITHM_SERVER_COMPAR_H

#include "State.h"
#include "Cell.h"

class compar {
public:
    bool operator()(State<Cell> a,State<Cell> b) {
    return (a.getShortestPath() >  b.getShortestPath());
}
};


#endif //SEARCHING_ALGORITHM_SERVER_COMPAR_H
