//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_CACHEMANAGER_H
#define SEARCHING_ALGORITHM_SERVER_CACHEMANAGER_H

template<class problem, class solution>
class CacheManager {
public:
    void insert(problem p, solution s) = 0;
    solution* get(problem p) = 0;
};

#endif //SEARCHING_ALGORITHM_SERVER_CACHEMANAGER_H
