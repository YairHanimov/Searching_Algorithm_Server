//
// Created by eyal on 16.1.2020.
//

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
    //int state = 0;                //one-to-one value of state in the Searchable
    vector<State<Cell>> myalloption;
public:
    bool operator==(State<T> other) {
        bool isEqual = obj == other.getObj();
        return isEqual;
    }

//    State<T>(T *obj, double cos) {
//        this->obj = obj;
//        this->parent = parent;
//        this->visited = false;
//        this->shortestPathCost = cos;
//        this->cost = cos;
//    }
//
    State<T>() {

    }
    State<T>(State<T> *mystate,int k) {
        this->setParent(mystate);
    }
    State<T>(State<T> *mystate) {
        this->obj = mystate->obj;
        this->shortestPathCost = mystate->shortestPathCost;
        this->visited = mystate->visited;
//        State<T> dammmy= new State(mystate->getParent() , 0);
//        this->parent =dammmy;

        this->cost = mystate->cost;

            this->setParent(mystate->getParent());

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

    void setobj(T *objj) {
        this->obj = objj;
    };

    State<T> getMe() {
        return *this;
    }

    void setParent(State<T> *p) {
//       if (this==p){
//           cout<<"wy they =??"<<endl;
//       }
//       else {
           this->parent = p;
//       }
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

    bool areviseted() {
        return this->visited;
    }

    void setviseted(bool t) {
        this->visited = t;
    };

    void setmyalloption(std::vector<State<Cell>> k) {
        this->myalloption = k;
    }

    std::vector<State<Cell>> getmyalloption() {
        return this->myalloption;
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_STATE_H
