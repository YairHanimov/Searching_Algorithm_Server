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
        string lexer="";
        int row=0;
        int call=0;
        int mysize=line.size();

        while(row<(mysize-3)){
            lexer+=line.front();
            line.pop_back();
            char *token = strtok(strToChar, ",");
            while (token != NULL) {
                Cell *c= new Cell(row,call);
                State<Cell> *st = new State<Cell>((double )atoi(token));
                call++;
                token = strtok(NULL, ",");
            }
            row++;
        }
        char *token = strtok(strToChar, ",");
        if (token != NULL) {
            double  start1=(double )atoi(token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            double  start2=(double )atoi(token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            double  end1=(double )atoi(token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            double  end2=(double )atoi(token);
            token = strtok(NULL, ",");
        }
        Cell *startcell=new Cell(start1,start2);
        Cell *endedsell=new Cell(start1,start2);
        State<Cell> *start = new State<Cell>()
    }


private:
    Searcher<problem> oa_searcher;
};


#endif //SEARCHING_ALGORITHM_SERVER_OA_H
