#ifndef SEARCHING_ALGORITHM_SERVER_ASTAR_H
#define SEARCHING_ALGORITHM_SERVER_ASTAR_H

#include "Searcher.h"
#include "queue"
#include "set"
#include "PriorityQueueState.h"
#include "Cell.h"
#include "compar.h"
#include "Matrix.h"
#include "comparforset.h"
#include "compareStar.h"

using namespace std;

template<class T>
class AStar : public Searcher<T> {
public:
    explicit AStar() {

    }

    string search(Matrix *problem) {
        vector<State<T>> path;
        vector<string> direct;

        double minPath = -1;
        double currentPathCost = 0;

        priority_queue<State<T> *, vector<State<T> *>, compareStar> mypq; // a priority queue of states to be evaluated
        auto initialNode = problem->getInitialState();
        initialNode.setShortestPath(initialNode.getCost());
        problem->givemegoalcell().setHeuristic(0);
        initialNode.setHeuristic(initialNode.getObj(), problem->givemegoalcell().getObj());
        mypq.push(&initialNode);
        initialNode.setVisited();

        set<State<T>, comparforset> closedNodesSet;  // a set of states already evaluated
        set<State<T>, comparforset> specialSearchSet;
        specialSearchSet.insert(initialNode);
        int evaluations = 0;
        while (!mypq.empty()) {

            evaluations++;
            State<T> *currentNode = (mypq.top());

            specialSearchSet.erase(mypq.top());
            (mypq.pop());

            closedNodesSet.insert(currentNode); // so we won't check currentNode again

            if (problem->isGoalState(currentNode)) {
                //build path
                int mytotalcost = 0;
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
                    if(jj != 1) {
                        pathSolution += direct[jj - 1] + ",";
                    }
                    else {
                        pathSolution += direct[jj - 1];
                    }
                }

                mytotalcost += currentNode->getCost();
                cout << "AStar:" << endl;
                cout << "Total evaluations:"<<endl;
                cout<<evaluations << endl;
                cout<<"Path:"<<endl;
                cout<<pathSolution<<endl;
                return pathSolution;

            } else {
                list<State<T> *> neighbors = problem->getAllPossibleStates(currentNode);
                //go over all neighbors of current node
                for (State<T> *currentNeighbor:neighbors) {
                    if ((closedNodesSet.find(currentNeighbor) == closedNodesSet.end()) &&
                        (specialSearchSet.find(currentNeighbor) == specialSearchSet.end())) {
                        currentNeighbor->setParent(currentNode);
                        currentNeighbor->setShortestPath(currentNode->getShortestPath() + currentNeighbor->getCost());
                        mypq.push(currentNeighbor);
                        specialSearchSet.insert(currentNeighbor);

                    } else {
                        if (currentNeighbor->getShortestPath() >
                            currentNode->getShortestPath() + currentNeighbor->getCost()) {

                            currentNeighbor->setShortestPath(
                                    currentNode->getShortestPath() + currentNeighbor->getCost());
                            currentNeighbor->setParent(currentNode);
                            if (specialSearchSet.find(currentNeighbor) == specialSearchSet.end()) {
                                mypq.push(currentNeighbor);
                                specialSearchSet.insert(currentNeighbor);
                            }
                        }
                    }
                }

            }
        }
    };

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
    AStar<T> *clone() override {
        return new AStar<T>();
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_ASTAR_H


