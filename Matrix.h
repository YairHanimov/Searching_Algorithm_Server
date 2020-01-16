//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MATRIX_H
#define SEARCHING_ALGORITHM_SERVER_MATRIX_H

#include "Searchable.h"
#include "State.h"
#include "Cell.h"

using namespace std;

class Matrix : public Searchable<Cell>{
public:
    vector<vector<State<Cell>>> matrix;
    State<Cell> start;
    State<Cell> end;
    virtual State<Cell> getInitialState() {
        return this->start;
    }
    virtual bool isGoalState(State<Cell> c){

    }
    virtual vector<State<Cell>> getAllPossibleStates(State<Cell>){}
};

#endif //SEARCHING_ALGORITHM_SERVER_MATRIX_H
