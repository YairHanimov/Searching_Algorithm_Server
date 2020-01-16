//
// Created by yair on 12/01/2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_STRINGREVERSER_H
#define SEARCHING_ALGORITHM_SERVER_STRINGREVERSER_H
#include "string"
#include "Solver.h"

using namespace std;

class StringReverser : public Solver <string,string> {
public:
    StringReverser() = default;
    string solve(string problem) override;
    string print();
};


#endif //SEARCHING_ALGORITHM_SERVER_STRINGREVERSER_H
