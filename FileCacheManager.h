
#ifndef SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
#define SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H

#include <list>
#include <fstream>
#include "unordered_map"
#include "CacheManager.h"
#include <unordered_map>

using namespace std;

template<class problem, class solution>
class FileCacheManager : public CacheManager<problem, solution> {
private:
    unordered_map<problem,string> map;
    solution s;
    int counter=1;
public:

    list<pair<problem, solution>> dq;
    unordered_map<problem, typename list<pair<problem, solution>>::iterator> cache;
    unsigned long capacity = 1;

    void insert(problem p, solution s) override {

        //create file with the problem as it's name
        string problemName = p;
        string mycounter=to_string(counter);
       this->map.insert({p,mycounter});
        map[problemName]+=mycounter+ ".txt";
        string solutionName = s;
        ofstream problemFile(map[problemName]);

        //check file created successfuly
        if (!problemFile) {
            throw "error opening file";
        }
          counter++;
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
        auto it = cache.find(p);
        if (it == cache.end()) {

            fstream in_file;
            string kal=p;

          string filename = this->map[kal];
           filename += ".txt";
          in_file.open(filename);
            if (!in_file.is_open()) {
                return nullptr;
            }
            string line = "";
            while(getline(in_file,line)) {
                s += line;
            }

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
