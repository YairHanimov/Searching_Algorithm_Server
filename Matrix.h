
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


    Matrix(vector<vector<State<Cell> *>> m, int start1, int start2, int end1, int end2) {
        this->matrix = m;

        Cell *starterCell = new Cell(start1, start2);
        Cell *endedCell = new Cell(end1, end2);
        this->start = m[start1][start2];
        this->end = m[end1][end2];
        setstartt(this->start);
        setendd(this->end);

    }

    State<Cell> getInitialState() override {
        return this->start;
    }

    bool isGoalState(State<Cell> c) override {
        return ((this->end->getObj()->getCol() == c.getObj()->getCol()) &&
                (this->end->getObj()->getRow() == c.getObj()->getRow()));
    }

    State<Cell> givemegoalcell() {
        return this->end;
    }

    virtual list<State<Cell> *> getAllPossibleStates(State<Cell> c) override {
        list<State<Cell> *> myoptionvector;
        int row = 0;
        int col = 0;
        int size = 0;
        int mysize = this->matrix.size() - 1;
        row = c.getObj()->getRow();
        col = c.getObj()->getCol();
        c.setVisited();
        if ((col != mysize) && ((matrix[row][col + 1]->getCost()) != (-1))) {
            {
                myoptionvector.push_back(matrix[row][col + 1]);
            }
        }
        if ((col != 0) && ((matrix[row][col - 1]->getCost()) != (-1))) {
            {

                myoptionvector.push_back(matrix[row][col - 1]);
            }
        }
        if ((row != mysize) && ((matrix[row + 1][col]->getCost()) != (-1))) {
            {

                myoptionvector.push_back(matrix[row + 1][col]);
            }
        }
        if ((row != 0) && ((matrix[row - 1][col]->getCost()) != (-1))) {
            {

                myoptionvector.push_back(matrix[row - 1][col]);
            }
        }
        return myoptionvector;
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_MATRIX_H