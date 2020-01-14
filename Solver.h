//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_SOLVER_H
#define SEARCHING_ALGORITHM_SERVER_SOLVER_H

#include "string"

using namespace std;

template<class problem, class solution>
class Solver {
public:
    virtual solution solve(problem) = 0;
};

#endif //SEARCHING_ALGORITHM_SERVER_SOLVER_H
