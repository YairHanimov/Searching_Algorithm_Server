
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
    //vector<State<Cell>> myalloption;
    int urist=0;
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
//    State<T>() {
//
//    }

    State<T>(State<T> *myState, int k) {
        this->setParent(myState);
    }

    State<T>(State<T> *myState) {


        this->obj = myState->obj;
        this->shortestPathCost = myState->shortestPathCost;

        this->cost = myState->cost;

//            this->parent = myState->parent;



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
    void setObj(T *objj) {
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
        if(p->parent == this) {
            cerr<<"Luke, I am your father"<<endl;
        }
        else {
            this->parent = p;
            this->visited = true;
        }
//       }
    }
    void seturistic(Cell *p ,Cell *goal ) {
        int re= abs((goal->getRow()-p->getRow()))+abs((goal->getCol()-p->getCol()));
        this->urist=re;
    }
    void seturistic(int g ) {
        this->urist=g;
    }
    int  geturistic( ) {
        return  this->urist;
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

    void setmyalloption(std::vector<State<Cell>> k) {
        this->myalloption = k;
    }

    std::vector<State<Cell>> getmyalloption() {
        return this->myalloption;
    }
};
#endif //SEARCHING_ALGORITHM_SERVER_STATE_H