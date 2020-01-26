
#ifndef SEARCHING_ALGORITHM_SERVER_STATE_H
#define SEARCHING_ALGORITHM_SERVER_STATE_H

#include <vector>
#include <iostream>
#include "Cell.h"

using namespace std;

template<class T>
class State {
private:
    T *obj;
    State<T> *parent = nullptr;     //where we came from
    bool visited = false;           //was visited or not
    double cost = 0;                //cost of visiting
    double shortestPathCost = 0;    //how much cost until now
    int heuristic = 0;

public:
    bool operator==(State<T> other) {
        bool isEqual = obj == other.getObj();
        return isEqual;
    }

    State<T>(State<T> *myState, int k) {
        this->setParent(myState);
    }

    State<T>(State<T> *myState) {

        this->obj = myState->obj;
        this->shortestPathCost = myState->shortestPathCost;

        this->cost = myState->cost;
    }


    explicit State<T>(T *inputObj) {
        this->obj = inputObj;
    }

    double getCost() {
        return this->cost;
    }

    void setCost(double c) {
        this->cost = c;
    }

    T *getObj() {
        return obj;

    }

    void setVisited() {
        this->visited = true;
    }

    bool getVisited() {
        return this->visited;
    }

    void setParent(State<T> *p) {
        if (p->parent == this) {
            cerr << "Infinite parent loop detected" << endl;
        } else {
            this->parent = p;
            this->visited = true;
        }
    }

    void setHeuristic(Cell *p, Cell *goal) {
        int re = abs((goal->getRow() - p->getRow())) + abs((goal->getCol() - p->getCol()));
        this->heuristic = re;
    }

    void setHeuristic(int g) {
        this->heuristic = g;
    }

    int getHeuristic() {
        return this->heuristic;
    }

    State<T> *getParent() {
        return parent;
    }

    double getShortestPath() {
        return this->shortestPathCost;
    }

    void setShortestPath(double sp) {
        this->shortestPathCost = sp;
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_STATE_H