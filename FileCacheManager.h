
#ifndef SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
#define SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H

#include <list>
#include <fstream>
#include  <unordered_map>
#include "CacheManager.h"

using namespace std;

template<class problem, class solution>
class FileCacheManager : public CacheManager<problem, solution> {
public:

    list<pair<problem, solution>> dq;
    unordered_map<string, typename list<pair<problem, solution>>::iterator> cache;
    unsigned long capacity = 0;

    void insert(problem p, solution s) override {
        ofstream in_file;
        string filename = p;
        in_file.open(filename, ios::binary);
        if (!in_file) {
            throw "error open file";
        }
        in_file.write((char *) &s, sizeof(s));
        in_file.close();
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

    solution* get(problem p) override {
        solution *s;
        auto it = cache.find(p);
        if (it == cache.end()) {
            // if (cache.find(p)==cache.end){
            fstream in_file;
            string filename = p;
            in_file.open(filename);
            if (!in_file) {
                return nullptr;
            }
            in_file.read((char *) &s, sizeof(s));
//            insert(p, s);
            in_file.close();
            return s;

        } else {

            dq.splice(dq.begin(), dq, it->second);
            insert(p, it->second->second);
            return &it->second->second;
        }
    }

    FileCacheManager() {
        this->capacity = 5;
    }
};

#endif //SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
