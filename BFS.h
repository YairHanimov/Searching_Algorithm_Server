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
    explicit BFS(Searchable<T> *p) {

    }

    vector<State<T>> search(Matrix *problem) {
        int evaluations = 0;
        queue<State<T>*> bfsQueue;

        State<T>* currentNode = problem->getInitialState();
        bfsQueue.push(currentNode);
        currentNode->setVisited();

        while(!bfsQueue.empty()) {
            evaluations++;
            list<State<T>*> neighbors = problem->getAllPossibleStates(currentNode);
            for (State<T> *currentNeighbor:neighbors) {
                if(!currentNeighbor->getVisited()) {
                    currentNeighbor->setVisited();
                    currentNeighbor->setShortestPath(currentNode->getShortestPath()+currentNeighbor->getCost());
                    currentNeighbor->setParent(currentNode);
                    bfsQueue.pop();
                }
            }
        }

    }
};


#endif //SEARCHING_ALGORITHM_SERVER_BFS_H
