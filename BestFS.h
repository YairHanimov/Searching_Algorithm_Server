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

    explicit BestFS() {

    }

    string search(Matrix *problem) {
        vector<State<T>> path;
        double minPath = -1;
        double currentPathCost = 0;
        string pathSolution = "";
        priority_queue<State<T> *, vector<State<T> *>, compar> mypq; // a priority queue of states to be evaluated
        auto initialNode = problem->getInitialState();
        initialNode.setShortestPath(initialNode.getCost());
        mypq.push(&initialNode);
        initialNode.setVisited();

        set<State<T>, comparforset> closedNodesSet;                    // a set of states already evaluated
        set<State<T>, comparforset> specialSearchSet;
        specialSearchSet.insert(initialNode);
        unsigned long evaluations = 0;
        while (!mypq.empty()) {

            evaluations++;
            State<T> *currentNode = (mypq.top());


            //         State<T> currentNode =   new State <T>(mypq.top());
            specialSearchSet.erase(mypq.top());
            (mypq.pop());

            //currentNode->setVisited();

            //currentPathCost = currentNode->getShortestPath();
            closedNodesSet.insert(currentNode);       // so we won't check currentNode again
            //  currentNode->setVisited();
            if (problem->isGoalState(currentNode)) {
                unsigned long mytotalcost = 0;
                vector<string> direct;
                vector<int> number;
                while (currentNode->getParent() != NULL) {
                    Cell *d = currentNode->getObj();
                    Cell *dp = currentNode->getParent()->getObj();
                    if (d->getCol() < dp->getCol()) {
                        int total = currentNode->getShortestPath();
                        string s = to_string(total);
                        direct.push_back("Left(" + s + ")");
                    }
                    if (d->getCol() > dp->getCol()) {
                        int total = currentNode->getShortestPath();
                        string s = to_string(total);
                        direct.push_back("Right(" + s + ")");
                    }
                    if (d->getRow() < dp->getRow()) {
                        int total = currentNode->getShortestPath();
                        string s = to_string(total);
                        direct.push_back("Up(" + s + ")");
                    }
                    if (d->getRow() > dp->getRow()) {
                        int total = currentNode->getShortestPath();
                        string s = to_string(total);
                        direct.push_back("Down(" + s + ")");
                    }
                    // mytotalcost +=currentNode->getCost();
                    currentNode = currentNode->getParent();
                }

                for (int jj = direct.size(); jj > 0; jj--) {
                    pathSolution += direct[jj - 1];
                }
                //  mytotalcost+=currentNode->getCost();
                cout << "BestFS:" << endl;
                cout << evaluations << endl;

                return pathSolution;
                // return backtrace(currentNode);
            } else {
                list<State<T> *> neighbors = problem->getAllPossibleStates(currentNode);
                //go over all neighbors of current node
                for (State<T> *currentNeighbor:neighbors) {
                    //todo : BUG: cell 0x0 passed this test even though it was in closedNoseSet
                    if ((closedNodesSet.find(currentNeighbor) == closedNodesSet.end()) &&
                        (specialSearchSet.find(currentNeighbor) == specialSearchSet.end())) {
                        currentNeighbor->setParent(currentNode);
                        // currentPathCost += currentNeighbor->getCost()+currentNode->getCost();
                        currentNeighbor->setShortestPath(currentNode->getShortestPath() + currentNeighbor->getCost());
                        mypq.push(currentNeighbor);
                        specialSearchSet.insert(currentNeighbor);

                    } else {
//                        currentPathCost += currentNeighbor.getCost()+currentNeighbor.getParent()->getShortestPath();
                        if (currentNeighbor->getShortestPath() >
                            currentNode->getShortestPath() + currentNeighbor->getCost()) {

                            currentNeighbor->setShortestPath(
                                    currentNode->getShortestPath() + currentNeighbor->getCost());
                            currentNeighbor->setParent(currentNode);
                            if (specialSearchSet.find(currentNeighbor) == specialSearchSet.end()) {
                                mypq.push(currentNeighbor);
                                specialSearchSet.insert(currentNeighbor);
                            }
//                            mypq.push(currentNeighbor);
//                            specialSearchSet.insert(currentNeighbor);
                        }
                    }
                }

            }
        }
//        return path;
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

    BestFS<T> *clone() override {
        return new BestFS<T>();
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_BESTFS_H