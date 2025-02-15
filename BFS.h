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
        queue<State<T> *> bfsQueue;

        auto initialNode = problem->getInitialState();
        bfsQueue.push(&initialNode);
        initialNode.setVisited();

        while (!bfsQueue.empty()) {
            evaluations++;
            State<T> *currentNode = bfsQueue.front();
            bfsQueue.pop();
            if (problem->isGoalState(currentNode)) {
                //build path
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

                    currentNode = currentNode->getParent();
                }
                string pathSolution = "";
                for (int jj = direct.size(); jj > 0; jj--) {
                    if (jj != 1) {
                        pathSolution += direct[jj - 1] + ",";
                    } else {
                        pathSolution += direct[jj - 1];
                    }
                }

                //print and return solution
                cout << "BFS:" << endl;
                cout << evaluations << endl;
                cout<<pathSolution<<endl;
                return pathSolution;
            }
            //go over node's neighbors
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

    //clone current object
    BFS<T> *clone() override {
        return new BFS<T>();
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_BFS_H
