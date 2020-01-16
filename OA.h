//
// Created by eyal on 16.1.2020.
//


#ifndef SEARCHING_ALGORITHM_SERVER_OA_H
#define SEARCHING_ALGORITHM_SERVER_OA_H

#include <cstring>
#include "Solver.h"
#include "Searcher.h"
# include "Matrix.h"
#include <unistd.h>

using namespace std;

template<class problem, class solution>
class OA : public Solver<string, string> {
public:
    OA() = default;

    string solve(string p) override {
        Matrix<string> m = stringtomatrix(p);
        cout<<"bla bla"<<endl;
    }

    Matrix<string> stringtomatrix(string str) {
        vector<string> line;
        int n = str.length();

        char strToChar[n + 1];
        strcpy(strToChar, str.c_str());
        char *token = strtok(strToChar, "\n");
        while (token != NULL) {

            //   cout << token << endl;
            line.push_back(token);

            token = strtok(NULL, "\n");

        }
    }

private:
    Searcher<problem> oa_searcher;
};


#endif //SEARCHING_ALGORITHM_SERVER_OA_H
