//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_STATE_H
#define SEARCHING_ALGORITHM_SERVER_STATE_H

template<class T>
class State {
private:
    T *obj;
    State<T> *parent;       //where we came from
    bool visited;           //was visited or not
    double cost;            //cost of visiting
    double shortestPath;    //how much cost until now
public:
    State<T>(T *inputObj){
        this->obj = inputObj;
        this->parent = nullptr;
        this->visited = false;
        this->cost = 0;
        this->shortestPath = 0;
    }
    void setCost(double c) {
        this->cost = c;
    }
    T getT(){
        return this->obj;
    }
    State<T> getParent(){}
    void setShortestPath(){}
};


#endif //SEARCHING_ALGORITHM_SERVER_STATE_H
