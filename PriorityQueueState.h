//
// Created by eyal on 19.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_PRIORITYQUEUESTATE_H
#define SEARCHING_ALGORITHM_SERVER_PRIORITYQUEUESTATE_H

#include "State.h"
#include "queue"
#include "unordered_set"
#include "Cell.h"
using namespace std;

template<class T>
class PriorityQueueState {
private:
    vector<State<T>*> pq;

public:
    void push(State<T>* newState) {
        vector<State<T>*> saver;
        while (newState->getCost() > pq.top->getCost() && !pq.empty()) {
            saver.push_back(pq.top());
            pq.erase(pq.top());
        }
        saver.push_back(newState);
        while(!pq.empty()) {
            saver.push_back(pq.top());
            pq.erase(pq.top());
        }
        while(!saver.empty()) {
            pq.push(saver.front());
            saver.erase(saver.front());
        }
    }

    bool isInPQ(State<T> *toFind) {
        for(typename vector<State<T>*>::iterator it = pq.front() ; it!=pq.end() ; it++) {
            if(*it == toFind) {
                return true;
            }
        }
        return false;
    }

    State<T>* pop() {
        State<T>* front = pq.front();
        pq.erase(pq.front());
        return front;
    }

    bool empty() {
        return this->pq.empty();
    }

    State<T>* top(){
        return this->pq.front();
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_PRIORITYQUEUESTATE_H
