//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_CACHEMANAGER_H
#define SEARCHING_ALGORITHM_SERVER_CACHEMANAGER_H

template<class problem, class solution>
class CacheManager {
public:
    unsigned long capacity = 0;
    virtual void insert(problem p, solution s) = 0;
    virtual solution* get(problem p) = 0;
    CacheManager(){
        this->capacity=5;
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_CACHEMANAGER_H
