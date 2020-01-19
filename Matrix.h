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

    virtual vector<State<Cell>> getAllPossibleStates(State<Cell> c) {
        vector<State<Cell>> myoptionvector;
            int row=0;
            int cell=0;
            int size=0;
            int mysize= this->matrix.size();
            row=c.getObj()->getRow();
            cell=c.getObj()->getCol();
            if ((cell!=mysize)&&((matrix[cell+1][row]->getCost())!= (-1))){
                myoptionvector.push_back(matrix[cell + 1][row]->getMe());
            }
           if ((cell!=0)&&((matrix[cell-1][row]->getCost())!= (-1))){
            myoptionvector.push_back(matrix[cell-1][row]->getme());
        }
        if ((row!=mysize)&&((matrix[cell][row+1]->getCost())!= (-1))){
            myoptionvector.push_back(matrix[cell][row+1]->getme());
        }
        if ((row!=0)&&((matrix[cell][row-1]->getCost())!= (-1))){
            myoptionvector.push_back(matrix[cell][row-1]->getme());
        }


    }
};

#endif //SEARCHING_ALGORITHM_SERVER_MATRIX_H
