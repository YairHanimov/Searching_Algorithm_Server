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
    double shortestPathCost = 0;    //how much cost until now
    //int state = 0;                //one-to-one value of state in the Searchable
public:
    bool operator==(State<T> other) {
        bool isEqual = this->obj == other.getObj();
        return isEqual;
    }
    State<T>(T *obj, State<T> *parent,bool visitef, double shorted, double cos){
        this->obj=obj;
        this->parent=parent;
        this->visited=visitef;
        this->shortestPathCost=shorted;
        this->cost=cos;
    }
    State<T>(){

    }
    State<T>(State<T> *mystate){
        this->obj=mystate->obj;
        this->shortestPathCost=mystate->shortestPathCost;
        this->visited=mystate->visited;
        this->parent=mystate->parent;
        this->cost=mystate->cost;
    }
    explicit State<T>(T *inputObj) {
        this->obj = inputObj;
    }

    double getCost(){
        return this->cost;
    }
    void setCost(double c) {
        this->cost = c;
    }

    T* getObj() {
        return this->obj;

    }
    void setobj(T *objj){
        this->obj=objj;
    };
    State<T> getMe(){
        return *this;
    }

    void setParent(State<T>* p) {
        this->parent = p;
    }
    State<T>* getParent() {
        return parent;
    }

    double getShortestPath() {
        return this->shortestPathCost;
    }
    void setShortestPath(double sp) {
        this->shortestPathCost = sp;
    }
    bool areviseted(){
        return this->visited;
    }
    void setviseted(bool t){
        this->visited=t;
    };
};


#endif //SEARCHING_ALGORITHM_SERVER_STATE_H
