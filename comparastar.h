//
// Created by yair on 23/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_COMPARASTAR_H
#define SEARCHING_ALGORITHM_SERVER_COMPARASTAR_H



#include "State.h"
#include "Cell.h"

class comparastar {
public:
    bool operator()(State<Cell> a,State<Cell> b) {
        return (a.geturistic()+a.getShortestPath() > b.geturistic()+b.getShortestPath());
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_COMPARASTAR_H