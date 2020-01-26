//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_BFS_H
#define SEARCHING_ALGORITHM_SERVER_BFS_H

#include "Searcher.h"
#include <list>
#include "queue"

using namespace std;

template<class T>
class BFS : public Searcher<T> {
public:
    explicit BFS() {

    }

    string search(Matrix *problem) {
        int evaluations = 0;
        queue<State<T>*> bfsQueue;

        auto initialNode = problem->getInitialState();
        bfsQueue.push(&initialNode);
        initialNode.setVisited();

        while (!bfsQueue.empty()) {
            evaluations++;
            State<T> *currentNode = bfsQueue.front();
            bfsQueue.pop();
            if (problem->isGoalState(currentNode)) {
//                cout<<evaluations<<endl;
//                cout<<currentNode->getShortestPath()<<endl;
                cout<<"BFS:"<<endl;
                cout <<evaluations<<endl;
//                return backtrace(currentNode);
            }

            list<State<T> *> neighbors = problem->getAllPossibleStates(currentNode);
            for (State<T> *currentNeighbor:neighbors) {
                if (!currentNeighbor->getVisited()) {
                    currentNeighbor->setVisited();
                    currentNeighbor->setShortestPath(currentNode->getShortestPath() + currentNeighbor->getCost());
                    currentNeighbor->setParent(currentNode);
                    bfsQueue.push(currentNeighbor);
                }
            }
        }
    }

    vector<State<T>> backtrace(State<T> goal) {
        vector<State<T>> path;
        path.push_back(goal);
        State<T> *parent = goal.getParent();

        while (parent != nullptr) {
            path.push_back(parent);
            *parent = parent->getParent();
        }
        return path;
    }

    BFS<T>* clone() override {
        return new BFS<T>();
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_BFS_H
