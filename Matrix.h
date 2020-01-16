//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MATRIX_H
#define SEARCHING_ALGORITHM_SERVER_MATRIX_H

#include "Searchable.h"
#include "State.h"
#include "Cell.h"

using namespace std;

class Matrix : public Searchable<Cell> {
public:
    vector<vector<State<Cell> *>> matrix;
    State<Cell> *start;
    State<Cell> *end;

    Matrix(vector<vector<State<Cell> *>> m, State<Cell> *s, State<Cell> *e) {
        this->matrix = m;
        this->start = s;
        this->end = e;
    }

    State<Cell> getInitialState() override {
        return *this->start;
    }

    bool isGoalState(State<Cell> c) override {

    }

    virtual vector<State<Cell>> getAllPossibleStates(State<Cell>) {}
};

#endif //SEARCHING_ALGORITHM_SERVER_MATRIX_H
