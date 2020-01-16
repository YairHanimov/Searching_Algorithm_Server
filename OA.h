//
// Created by eyal on 16.1.2020.
//

#include "Solver.h"
#include "Searcher.h"

#ifndef SEARCHING_ALGORITHM_SERVER_OA_H
#define SEARCHING_ALGORITHM_SERVER_OA_H

template<class problem, class solution>
class OA : public Solver<problem, solution> {
private:
    Searcher<problem> oa_searcher;
};


#endif //SEARCHING_ALGORITHM_SERVER_OA_H
