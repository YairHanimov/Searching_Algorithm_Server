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
#include "Cell.h"
#include "State.h"
#include "Searcher.h"
#include "BestFS.h"
#include "BFS.h"
#include "AStar.h"
#include "DFS.h"

using namespace std;

template<class problem, class solution>
class OA : public Solver<string, string> {
public:
    OA() = default;

    string solve(string p) override {
        //checking problem isnt empty
        string tester = "";
        if(p==tester){
            return "";
        }
        cout << "Problem received by Object Adapter..." << endl;
        Matrix *m = stringToMatrix(p);
        Searcher<Cell> *aStart = new AStar<Cell>();
        cout << "Trying to solve the problem with AStar..." << endl;
        string strAstar = aStart->search(m);
        cout << "---Finished solving with AStar---" << endl;
        return strAstar;
    }

    //building matrix from string input
    Matrix *stringToMatrix(const string str) {
        vector<string> line;
        int n = str.length();

        char strToChar[n + 1];
        strcpy(strToChar, str.c_str());
        char *token = strtok(strToChar, "\r\n");
        while (token != nullptr) {

            line.push_back(token);

            token = strtok(nullptr, "\r\n");

        }
        string lexer;
        int row = 0;
        int col = 0;
        int mysize = line.size();
        vector<vector<State<Cell> *>> matrix;
        while (row < (mysize - 2)) {
            vector<State<Cell> *> stateLine;
            lexer += line.front();
            line.erase(line.begin());
            strcpy(strToChar, lexer.c_str());
            token = strtok(strToChar, ",");
            while (token != nullptr) {
                Cell *c = new Cell(row, col);
                auto *st = new State<Cell>(c);
                st->setCost(stod(token));
                stateLine.push_back(st);
                col++;
                token = strtok(nullptr, ",");
            }
            lexer = "";
            matrix.push_back(stateLine);
            row++;
            col = 0;
        }
        int start1 = 0;
        int start2 = 0;
        int end1 = 0;
        int end2 = 0;
        strcpy(strToChar, line.front().c_str());
        token = strtok(strToChar, ",");
        if (token != nullptr) {
            start1 = atoi(token);
            token = strtok(nullptr, ",");
        }
        if (token != nullptr) {
            start2 = atoi(token);
            token = strtok(nullptr, ",");
        }
        line.erase(line.begin());
        strcpy(strToChar, line.front().c_str());
        token = strtok(strToChar, ",");

        if (token != nullptr) {
            end1 = atoi(token);
            token = strtok(nullptr, ",");
        }
        if (token != nullptr) {
            end2 = atoi(token);
            token = strtok(nullptr, ",");
        }

        //returining the built matrix
        Matrix *returnMatrix = new Matrix(matrix, start1, start2, end1, end2);
        int test = matrix.size();
        return returnMatrix;
    }

    //clone current object
    OA *clone() override {
        Searcher<Cell> *clonedSearcher;
        OA *clonedOA = new OA<string, string>();
        return clonedOA;
    }


private:
//    Searcher<problem> oa_searcher;
};


#endif //SEARCHING_ALGORITHM_SERVER_OA_H
