
#ifndef SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
#define SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H

#include <list>
#include <fstream>
#include "unordered_map"
#include "CacheManager.h"

using namespace std;

template<class problem, class solution>
class FileCacheManager : public CacheManager<problem, solution> {
private:
    solution s;
public:

    list<pair<problem, solution>> dq;
    unordered_map<problem, typename list<pair<problem, solution>>::iterator> cache;
    unsigned long capacity = 1;

    void insert(problem p, solution s) override {

        //create file with the problem as it's name
        string problemName = p;
        problemName += ".txt";
        string solutionName = s;
        ofstream problemFile(problemName);

        //check file created successfuly
        if (!problemFile) {
            throw "error opening file";
        }

        //write solution to file
        problemFile << solutionName.c_str() << endl;

        problemFile.close();
        auto it = cache.find(p);
        dq.push_front(pair<problem, solution>(p, s));
        if (it != cache.end()) {
            dq.erase(it->second);
            cache.erase(it);
        }
        cache[p] = dq.begin();

        if (cache.size() > capacity) {
            auto last = dq.end();
            last--;
            cache.erase(last->first);
            dq.pop_back();
        }
    }

    solution *get(problem p) override {
        this->s;
        auto it = cache.find(p);
        if (it == cache.end()) {

            fstream in_file;
            string filename = p;
            in_file.open(filename);
            if (!in_file) {
                return nullptr;
            }
            in_file.read((char *) &s, sizeof(s));

            in_file.close();
            return &s;

        } else {

            dq.splice(dq.begin(), dq, it->second);
            insert(p, it->second->second);
            return &it->second->second;
        }
    }

    FileCacheManager() {
        this->capacity = 0;
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
