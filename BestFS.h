//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_BESTFS_H
#define SEARCHING_ALGORITHM_SERVER_BESTFS_H

#include "Searcher.h"
#include "queue"
#include "set"
#include "PriorityQueueState.h"
#include "Cell.h"
#include "compar.h"
#include "Matrix.h"
#include "comparforset.h"

using namespace std;

template<class T>
class BestFS : public Searcher<T> {
public:

    explicit BestFS(Searchable<T> *p) {

    }

    vector<State<T>> search(Matrix *problem) {
        vector<State<T>> path;
        double minPath = -1;
        double currentPathCost = 0;

        priority_queue<State<T>*, vector<State<T>*>, compar> mypq; // a priority queue of states to be evaluated
        auto initialNode = problem->getInitialState();
        mypq.push(&initialNode);
        initialNode.setVisited();

        set<State<T>, comparforset> closedNodesSet;                    // a set of states already evaluated
        set<State<T>, comparforset> specialSearchSet;
        specialSearchSet.insert(initialNode);

        while (!mypq.empty()) {

            State<T> *currentNode =(mypq.top());
   //         State<T> currentNode =   new State <T>(mypq.top());
            specialSearchSet.erase(mypq.top());
            (mypq.pop());
            currentNode->setVisited();

            currentPathCost = currentNode->getShortestPath();
            closedNodesSet.insert(currentNode);       // so we won't check currentNode again
            currentNode->setVisited();
            if (problem->isGoalState(currentNode)) {
                return backtrace(currentNode);
            } else {
                vector<State<T>> neighbors = problem->getAllPossibleStates(currentNode);
                //go over all neighbors of current node
                for (typename vector<State<T>>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
                    State<T> currentNeighbor = *it;
                    //todo : BUG: cell 0x0 passed this test even though it was in closedNoseSet
                    if ((closedNodesSet.find(currentNeighbor) == closedNodesSet.end())&&
                            (specialSearchSet.find(currentNeighbor) == specialSearchSet.end())  ) {
                        currentNeighbor.setParent(currentNode);
                        currentPathCost += currentNeighbor.getCost()+currentNode->getCost();
                        currentNeighbor.setShortestPath(currentPathCost);
                        mypq.push(&currentNeighbor);
                        specialSearchSet.insert(currentNeighbor);

                    } else {
//                        currentPathCost += currentNeighbor.getCost()+currentNeighbor.getParent()->getShortestPath();
                        if (currentNeighbor.getShortestPath() >
                            currentNode->getShortestPath() + currentNeighbor.getCost()) {
                            currentNeighbor.setShortestPath(currentNode->getShortestPath() + currentNeighbor.getCost());
                            currentNeighbor.setParent(currentNode);
                            mypq.push(&currentNeighbor);
                            specialSearchSet.insert(currentNeighbor);
                        }
                    }
                }

            }
        }
        return path;
    };

//    bool inStateInSet(set<State<T>, compar> closedNodesSet, State<T> toFind) {
//        for(typename set<State<T>, compar>::iterator it = closedNodesSet.begin() ; it != closedNodesSet.end() ; it++) {
//            if(it == toFind){
//                return true;
//            }
//            return false;
//        }
//
//    }
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
};


#endif //SEARCHING_ALGORITHM_SERVER_BESTFS_H
