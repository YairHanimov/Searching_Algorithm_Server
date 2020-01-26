//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_DFS_H
#define SEARCHING_ALGORITHM_SERVER_DFS_H

#include "Searcher.h"
#include <list>
#include <stack>
#include "Searcher.h"

using namespace std;

template<class T>
class DFS : public Searcher<T> {
public:
public:
    explicit DFS() {

    }

    string search(Matrix *problem) {
        int evaluations = 0;
        stack<State<T> *> dfsStack;

        auto initialNode = problem->getInitialState();
        dfsStack.push(&initialNode);
        initialNode.setVisited();

        while (!dfsStack.empty()) {
            evaluations++;
            State<T> *currentNode = dfsStack.top();
            dfsStack.pop();
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
                string pathSolution = "";
                for (int jj = direct.size(); jj > 0; jj--) {
                    if (jj != 1) {
                        pathSolution += direct[jj - 1] + ",";
                    } else {
                        pathSolution += direct[jj - 1];
                    }
                }


                cout << "DFS:" << endl;
                cout << evaluations << endl;
                cout << pathSolution << endl;
                return pathSolution;

            }

            list<State<T> *> neighbors = problem->getAllPossibleStates(currentNode);
            for (State<T> *currentNeighbor:neighbors) {
                if (!currentNeighbor->getVisited()) {
                    currentNeighbor->setVisited();
                    currentNeighbor->setShortestPath(currentNode->getShortestPath() + currentNeighbor->getCost());
                    currentNeighbor->setParent(currentNode);
                    dfsStack.push(currentNeighbor);
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

    DFS<T> *clone() override {
        return new DFS<T>();
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_DFS_H
