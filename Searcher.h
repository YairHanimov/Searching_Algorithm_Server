//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_SEARCHER_H
#define SEARCHING_ALGORITHM_SERVER_SEARCHER_H

#include "Searchable.h"
#include "Matrix.h"

template<class T>
class Searcher {
public:
    virtual vector<State<T>> search(Matrix *pMatrix)=0;
    virtual Searcher<T>* clone() = 0;
};


#endif //SEARCHING_ALGORITHM_SERVER_SEARCHER_H
