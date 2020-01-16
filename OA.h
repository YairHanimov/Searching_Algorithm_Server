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

using namespace std;

template<class problem, class solution>
class OA : public Solver<string, string> {
public:
    OA() = default;

    string solve(string p) override {
        Matrix m = stringToMatrix(p);
        cout << "bla bla" << endl;
    }

    Matrix stringToMatrix(string str) {
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
        string lexer = "";
        int row = 0;
        int col = 0;
        int mysize = line.size();
        vector<vector<State<Cell>>> matrix;
        while (row < (mysize - 3)) {
            vector<State<Cell>> stateLine;
            lexer += line.front();
            line.pop_back();
            token = strtok(strToChar, ",");
            while (token != NULL) {
                Cell *c = new Cell(row, col);
                State<Cell> *st = new State<Cell>(c);
                st->setCost((double) atoi(token));
                stateLine.push_back(*st);
                col++;
                token = strtok(NULL, ",");
            }
            matrix.push_back(stateLine);
            row++;
        }
        double start1;
        double start2;
        double end1;
        double end2;
        token = strtok(strToChar, ",");
        if (token != NULL) {
            start1 = (double) atoi(token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            start2 = (double) atoi(token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            end1 = (double) atoi(token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            end2 = (double) atoi(token);
            token = strtok(NULL, ",");
        }
        Cell *startcell = new Cell(start1, start2);
        Cell *endedsell = new Cell(end1, end2);

        Matrix *returnMatrix;
        returnMatrix->matrix = matrix;
        *returnMatrix->start = startcell;
        *returnMatrix->end = endedsell;

//        Matrix *returnMatrix = new Matrix(matrix, *startcell, *endedsell);
        return *returnMatrix;
    }


private:
    Searcher<problem> oa_searcher;
};


#endif //SEARCHING_ALGORITHM_SERVER_OA_H
