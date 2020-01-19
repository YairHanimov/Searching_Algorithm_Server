//
// Created by eyal on 19.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_STATECOMPARE_H
#define SEARCHING_ALGORITHM_SERVER_STATECOMPARE_H

#include "State.h"

using namespace std;

template<class T>
class StateCompare {
public:
    bool operator()(State<T> *first, State<T>* second) {
        return first->getCost() > second->getCost();
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_STATECOMPARE_H
