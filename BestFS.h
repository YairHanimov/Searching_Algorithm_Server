//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_BESTFS_H
#define SEARCHING_ALGORITHM_SERVER_BESTFS_H

#include "Searcher.h"
#include "queue"
#include "set"

using namespace std;

template<class T>
class BestFS : public Searcher<T> {
public:
    vector<vector<T>*> search(Searchable<T>* searchable) override {
        vector<State<T>*> path;
        priority_queue<T> open;                    // a priority queue of states to be evaluated
        open.push(searchable->getInitialState());

        set<T> closed;                             // a set of states already evaluated

        while(!open.empty()) {
            // remove the best node from open
            T n = open.top();
            open.pop();

            closed.insert(n); // so we won't check n again

            if(searchable->isGoalState(n)) {

            }
            vector<T> * neighbors = searchable->getAllPossibleStates(n);
            for(typename vector<T>::iterator it = neighbors->begin() ; it != neighbors->end() ; it++) {

            }
        }
    };
};


#endif //SEARCHING_ALGORITHM_SERVER_BESTFS_H
