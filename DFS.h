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
class DFS : public Searcher<T>{
public:
public:
    explicit DFS() {

    }

   string search(Matrix *problem) {
        int evaluations = 0;
        stack<State<T>*> dfsStack;

        auto initialNode = problem->getInitialState();
        dfsStack.push(&initialNode);
        initialNode.setVisited();

        while (!dfsStack.empty()) {
            evaluations++;
            State<T> *currentNode = dfsStack.top();
            dfsStack.pop();
            if (problem->isGoalState(currentNode)) {
//                cout<<evaluations<<endl;
//                cout<<currentNode->getShortestPath()<<endl;
                cout<<"dfs:"<<endl;
                cout <<evaluations<<endl;
                return to_string(evaluations);
                //                return backtrace(currentNode);
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

    DFS<T>* clone() override {
        return new DFS<T>();
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_DFS_H
