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
using namespace std;

template<class T>
class BestFS : public Searcher<T> {
public:
    Searchable<T> problem;
    explicit BestFS(Searchable<T> *p) {
       this->problem = *p;
    }
    vector<State<T>> search() override {
        vector<State<T>> path;
        double minPath = -1;
        double currentPathCost = 0;
     //   PriorityQueueState<State<T>> openNodesPQ;            // a priority queue of states to be evaluated
      priority_queue<State<T>,vector<State<T>>,compar> mypq;
    //   bool test= openNodesPQ.empty();
       auto k =this->problem.getInitialState();
        mypq.push(k);
//
        set<State<T>,compar> closedNodesSet;                    // a set of states already evaluated
        set<State<T>,compar> spicialsearchq;
        spicialsearchq.insert(k);
      while (!mypq.empty()) {
//
//            // remove the best node from openNodesPQ
           State<T> currentNode = mypq.top();
   //         State<T> currentNode = new State<T>();
          //  currentNode.setCost(openNodesPQ.top().getCost());
         //   auto test=mypq.top().getObj();
//            currentNode.setobj(openNodesPQ.top().getObj());
 //           currentNode.setParent(openNodesPQ.top().getParent());
         //   currentNode.setShortestPath(openNodesPQ.top().getShortestPath());
         //   currentNode.setviseted(openNodesPQ.top().areviseted());
//            currentPathCost = openNodesPQ.top().getShortestPath();
             spicialsearchq.erase(mypq.top());

               mypq.pop();
            currentPathCost = currentNode.getShortestPath();
             closedNodesSet.insert(currentNode);       // so we won't check currentNode again

            if (this->problem.isGoalState(currentNode)) {
                return backtrace(currentNode);
            } else {
                vector<State<T>> neighbors = this->problem.getAllPossibleStates(currentNode);

                //go over all neighbors of current node
                for (typename vector<State<T>>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
                    State<T> currentNeighbor = *it;
                if    (closedNodesSet.find(currentNeighbor) == closedNodesSet.end() &&
                            (spicialsearchq.find(currentNeighbor)!=spicialsearchq.end())) {

                        currentNeighbor.setParent(&currentNode);
                        mypq.push(currentNeighbor);
                        spicialsearchq.insert(currentNeighbor);
                        currentPathCost += currentNeighbor.getCost();
                        currentNeighbor.setShortestPath(currentPathCost);
                    } else {
                        currentPathCost += currentNeighbor.getCost();
                        if (currentPathCost < currentNeighbor.getShortestPath()) {
                            currentNeighbor.setShortestPath(currentPathCost);
                      }
                   }
               }

               }
     }
      return path;
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
};


#endif //SEARCHING_ALGORITHM_SERVER_BESTFS_H
