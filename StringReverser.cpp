//
// Created by yair on 12/01/2020.
//

#include "StringReverser.h"
#include <bits/stdc++.h>
using namespace std;
string StringReverser::solve(string problem) {
    reverse(problem.begin(), problem.end());
    return problem;

}