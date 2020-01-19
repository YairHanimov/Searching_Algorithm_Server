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
//    int start1;
//    int start2;
//    int end1;
//    int end2;
    Matrix(vector<vector<State<Cell> *>> m, int start1,int start2,int end1,int end2) {
        this->matrix = m;
//        this->start1=start1;
//        this->start2=start2;
//        this->end1=end1;
//        this->end2=end2;
        Cell *starterCell = new Cell(start1, start2);
        Cell *endedCell = new Cell(end1, end2);
        this->start=new State<Cell>(starterCell);
        this->end= new State<Cell>(endedCell);
    }
//    Matrix(vector<vector<State<Cell> *>> m, State<Cell> *s, State<Cell> *e) {
//        this->matrix = m;
//        this->start = s;
//        this->end = e;
//    }

    State<Cell> getInitialState() override {
       return *this->start;
    }

    bool isGoalState(State<Cell> c) override {

    }

    virtual vector<State<Cell>> getAllPossibleStates(State<Cell>) {}
};

#endif //SEARCHING_ALGORITHM_SERVER_MATRIX_H
