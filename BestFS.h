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
    vector<vector<T> *> search(Searchable<State<T>> *searchable) override {
        vector<State<T> *> path;
        priority_queue<State<T>> openNodesPQ;                    // a priority queue of states to be evaluated
        openNodesPQ.push(searchable->getInitialState());

        set<State<T>> closedNodesSet;                             // a set of states already evaluated

        while (!openNodesPQ.empty()) {
            // remove the best node from openNodesPQ
            State<T> n = openNodesPQ.top();
            openNodesPQ.pop();

            closedNodesSet.insert(n); // so we won't check n again

            if (searchable->isGoalState(n)) {
                path = backtrace(n);
            } else {
                vector<State<T>> *neighbors = searchable->getAllPossibleStates(n);
                for (typename vector<State<T>>::iterator it = neighbors->begin(); it != neighbors->end(); it++) {
                }
            }
        }
        return path;
    };

    vector<vector<State<T>> *> backtrace(State<T> *goal) {
        vector<vector<T> *> path;
        path.push_back(goal);
        State<T> *parent = goal->getParent();

        while (parent != nullptr) {
            path.push_back(parent);
            parent = parent->getParent();
        }
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_BESTFS_H
