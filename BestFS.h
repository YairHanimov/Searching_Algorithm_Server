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
        double minPath = -1;
        double currentPathCost = 0;
        priority_queue<State<T>> openNodesPQ;            // a priority queue of states to be evaluated
        openNodesPQ.push(searchable->getInitialState());

        set<State<T>> closedNodesSet;                    // a set of states already evaluated

        while (!openNodesPQ.empty()) {

            // remove the best node from openNodesPQ
            State<T> currentNode = openNodesPQ.top();
            openNodesPQ.pop();
            currentPathCost = currentNode.getShortestPath();
            closedNodesSet.insert(currentNode);       // so we won't check currentNode again

            if (searchable->isGoalState(currentNode)) {
                path = backtrace(currentNode);
            } else {
                vector<State<T>> *neighbors = searchable->getAllPossibleStates(currentNode);

                //go over all neighbors of current nude
                for (typename vector<State<T>>::iterator it = neighbors->begin(); it != neighbors->end(); it++) {
                    State<T> *currentNeighbor = *it;
                    if (closedNodesSet.find(currentNeighbor) == closedNodesSet.end() &&
                        openNodesPQ.find(currentNeighbor) == openNodesPQ.end()) {
                        currentNeighbor->setParent(currentNode);
                        openNodesPQ.push(currentNeighbor);
                        currentPathCost += currentNeighbor->getCost();
                        currentNeighbor->setShortestPath(currentPathCost);
                    } else {
                        currentPathCost += currentNeighbor->getCost();
                        if(currentPathCost < currentNeighbor->getShortestPath()) {
                            currentNeighbor->setShortestPath(currentPathCost);
                        }
                    }
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
