//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_ASTAR_H
#define SEARCHING_ALGORITHM_SERVER_ASTAR_H

#include "Searcher.h"
using namespace std;

template<class T>
class AStar : public Searcher<T>{
public:
    virtual T search (Searchable<T>){

    };
};


#endif //SEARCHING_ALGORITHM_SERVER_ASTAR_H
