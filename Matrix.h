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

    Matrix(vector<vector<State<Cell> *>> m, int start1, int start2, int end1, int end2) {
        this->matrix = m;
//        this->start1=start1;
//        this->start2=start2;
//        this->end1=end1;
//        this->end2=end2;
        Cell *starterCell = new Cell(start1, start2);
        Cell *endedCell = new Cell(end1, end2);
        this->start = new State<Cell>(starterCell);
        this->end = new State<Cell>(endedCell);
        setstartt(this->start);
        setendd(this->end);

    }
//    Matrix(vector<vector<State<Cell> *>> m, State<Cell> *s, State<Cell> *e) {
//        this->matrix = m;
//        this->start = s;
//        this->end = e;
//    }

     State<Cell> getInitialState() override {
        return this->start;
    }

    bool isGoalState(State<Cell> c) override {
        return ((this->end->getObj()->getCol()==c.getObj()->getCol())&&
                (this->end->getObj()->getRow()==c.getObj()->getRow()));
    }

    virtual  vector<State<Cell>> getAllPossibleStates(State<Cell> c) override  {
        vector<State<Cell>> myoptionvector;
        int row = 0;
        int cell = 0;
        int size = 0;
        int mysize = this->matrix.size()-1;
        row = c.getObj()->getRow();
        cell = c.getObj()->getCol();
        c.setviseted(true);
        if ((cell != mysize) && ((matrix[row][cell + 1]->getCost()) != (-1))) {
             if(!matrix[row][cell + 1]->areviseted()) {
                 myoptionvector.push_back(matrix[row][cell + 1]->getMe());
             }
        }
        if ((cell != 0) && ((matrix[row][cell - 1]->getCost()) != (-1))) {
            if(!matrix[row][cell - 1]->areviseted()) {

                myoptionvector.push_back(matrix[row][cell - 1]->getMe());
            }
        }
        if ((row != mysize) && ((matrix[row + 1][cell]->getCost()) != (-1))) {
            if(!matrix[row+1][cell]->areviseted()) {

                myoptionvector.push_back(matrix[row + 1][cell]->getMe());
            }
        }
        if ((row != 0) && ((matrix[row - 1][cell]->getCost()) != (-1))) {
            if(!matrix[row-1][cell]->areviseted()) {

                myoptionvector.push_back(matrix[row - 1][cell]->getMe());
            }
        }
        return myoptionvector;
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_MATRIX_H
