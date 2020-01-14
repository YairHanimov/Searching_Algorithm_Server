//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
#define SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H

#import "unordered_map"

using namespace std;

template<class problem, class solution>
class FileCacheManager {
public:
    unordered_map<problem, solution> cache;
    bool isProblemSolver(string p);
};

#endif //SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
