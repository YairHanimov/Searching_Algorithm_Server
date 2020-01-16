//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_MATRIX_H
#define SEARCHING_ALGORITHM_SERVER_MATRIX_H

#include "Searchable.h"
#include "State.h"
using namespace std;

template<class T>
class Matrix : public Searchable<T>{
public:
    vector<vector<State<T>>> matrix;
};

#endif //SEARCHING_ALGORITHM_SERVER_MATRIX_H
