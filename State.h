//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_STATE_H
#define SEARCHING_ALGORITHM_SERVER_STATE_H

template<class T>
class State {
private:
    T *obj;
    State<T> *parent = nullptr;     //where we came from
    bool visited = false;           //was visited or not
    double cost = 0;                //cost of visiting
    double shortestPath = 0;        //how much cost until now
    //int state = 0;                  //one-to-one value of state in the Searchable
public:
    explicit State<T>(T *inputObj) {
        this->obj = inputObj;
    }

    void setCost(double c) {
        this->cost = c;
    }

    T getT() {
        return this->obj;
    }

    State<T> getParent() {}

    void setShortestPath() {}
};


#endif //SEARCHING_ALGORITHM_SERVER_STATE_H
