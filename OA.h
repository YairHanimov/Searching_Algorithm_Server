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

using namespace std;

template<class problem, class solution>
class OA : public Solver<string, string> {
public:
    OA() = default;

    string solve(string p) override {
        Matrix *m = stringToMatrix(p);
        Searcher<Cell>* bestFS = new BestFS<Cell>(m);
        vector<State<Cell>> bestFS_solution = bestFS->search(m);
        return solutionTOString(bestFS_solution);
        cout << "bla bla" << endl;
    }
    string solutionTOString (vector<State<Cell>> sol) {
        string stringSol = to_string(sol.back().getShortestPath());
        return stringSol;
    }
    Matrix* stringToMatrix(const string str) {
        vector<string> line;
        int n = str.length();

        char strToChar[n + 1];
        strcpy(strToChar, str.c_str());
        char *token = strtok(strToChar, "\n");
        while (token != nullptr) {

            //   cout << token << endl;
            line.push_back(token);

            token = strtok(nullptr, "\n");

        }
        string lexer;
        int row = 0;
        int col = 0;
        int mysize = line.size();
        vector<vector<State<Cell>*>> matrix;
        while (row < (mysize - 3)) {
            vector<State<Cell>*> stateLine;
            lexer += line.front();
            line.erase(line.begin());
            strcpy(strToChar, lexer.c_str());
        //    line.pop_back();
            token = strtok(strToChar, ",");
            while (token != nullptr) {
                Cell *c = new Cell(row, col);
                auto* st = new State<Cell>(c);
                st->setCost(stod(token));
                stateLine.push_back(st);
                col++;
                token = strtok(nullptr, ",");
            }
            lexer="";
            matrix.push_back(stateLine);
            row++;
            col=0;
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
//        Cell *startCell = new Cell(start1, start2);
//        Cell *endCell = new Cell(end1, end2);
//
//        auto* start = new State<Cell>(startCell);
//        auto* end = new State<Cell>(endCell);
//        returnMatrix->matrix = matrix;
//        returnMatrix->start = start;
//        returnMatrix->end = end;

        Matrix *returnMatrix = new Matrix(matrix,start1,start2,end1,end2);
        int test = matrix.size();
        return returnMatrix;
    }


private:
//    Searcher<problem> oa_searcher;
};


#endif //SEARCHING_ALGORITHM_SERVER_OA_H
