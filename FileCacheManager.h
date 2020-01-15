//
// Created by eyal on 12.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
#define SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H

#import "unordered_map"
#import "CacheManager.h"

using namespace std;

template<class problem, class solution>
class FileCacheManager : public CacheManager<problem,solution> {
public:
    unordered_map<problem, solution> cache;
    bool isProblemSolver(string p);

    list<pair<string, T>> dq;
    unordered_map<string, typename list< pair<string, T>>::iterator> mymap;
    unsigned long capacity;
    void insert(string key, T obj) {
        std:: ofstream in_file;
        std::string filename=obj.class_name+key;
        in_file.open(filename,::std::ios::binary);
        if (! in_file){
            throw"eror open file";
        }
        in_file.write((char*)&obj, sizeof(obj));
        in_file.close();
        auto it = mymap.find(key);
        dq.push_front(pair<string, T>(key, obj));
        if (it != mymap.end()) {
            dq.erase(it->second);
            mymap.erase(it);
        }
        mymap[key] = dq.begin();

        if (mymap.size() > capacity) {
            auto last = dq.end();
            last--;
            mymap.erase(last->first);
            dq.pop_back();
        }
    };

    T get(string key) {
        T obj;
        auto it = mymap.find(key);
        if (it == mymap.end()) {
            // if (mymap.find(key)==mymap.end){
            std::fstream in_file;
            std::string filename = obj.class_name + key;
            in_file.open(filename);
            if (!in_file) {
                throw "an error";
            }
            in_file.read((char*)&obj, sizeof(obj));
            insert(key,obj);
            in_file.close();
            return obj;

        } else {

            dq.splice(dq.begin(),dq,it->second);
            insert(key, it->second->second);
            return it->second->second;
        }


    };
    CacheManager(unsigned long cap) {
        this->capacity = cap;
    };
    void foreach(){

    };

    void foreach(function<void(T&)>func){
        for (auto x: dq){
            func(x.second);
        }
    }
};
};

#endif //SEARCHING_ALGORITHM_SERVER_FILECACHEMANAGER_H
