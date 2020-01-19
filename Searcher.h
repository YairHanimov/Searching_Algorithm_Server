//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_SEARCHER_H
#define SEARCHING_ALGORITHM_SERVER_SEARCHER_H

#include "Searchable.h"

template<class T>
class Searcher {
public:
    virtual vector<vector<T> *> search (Searchable<T> *){};
};


#endif //SEARCHING_ALGORITHM_SERVER_SEARCHER_H
