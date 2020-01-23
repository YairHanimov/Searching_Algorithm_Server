//
// Created by yair on 21/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_COMPARFORSET_H
#define SEARCHING_ALGORITHM_SERVER_COMPARFORSET_H
#include "State.h"
#include "Cell.h"

class comparforset {
public:
    bool operator()(State<Cell> a,State<Cell> b) {
        return (a.getObj() < b.getObj());
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_COMPARFORSET_H
