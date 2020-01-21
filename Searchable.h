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
protected:
    State<T*> *start;
    State<T*> *end;
public:
    virtual State<T*>* getInitialState() {
        return this->start;
    }

    virtual bool isGoalState(State<T*> k) {
        bool isEqual = this->end->getObj() == k.getObj();
        return isEqual;
    }

    virtual vector<State<T*>> getAllPossibleStates(State<T*> l) = 0;

//    virtual void setStart(State<T> *s) {
//        this->start = s;
//    }
//
//    virtual void setEnd(State<T> *e) {
//        this->end = e;
//    }

};


#endif //SEARCHING_ALGORITHM_SERVER_SEARCHABLE_H
