//
// Created by yair on 23/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_COMPARESTAR_H
#define SEARCHING_ALGORITHM_SERVER_COMPARESTAR_H


#include "State.h"
#include "Cell.h"

class compareStar {
public:
    bool operator()(State<Cell> a, State<Cell> b) {
        return (a.getHeuristic() + a.getShortestPath() > b.getHeuristic() + b.getShortestPath());
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_COMPARESTAR_H