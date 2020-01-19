//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_SEARCHABLE_H
#define SEARCHING_ALGORITHM_SERVER_SEARCHABLE_H

#include "State.h"
#include "vector"
using namespace std;

template<class T>
class Searchable {
public:
    virtual State<T> getInitialState() {}
    virtual bool isGoalState(State<T>){}
    virtual vector<State<T>> getAllPossibleStates(State<T>){

    }
};


#endif //SEARCHING_ALGORITHM_SERVER_SEARCHABLE_H
