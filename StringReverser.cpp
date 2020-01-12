//
// Created by yair on 12/01/2020.
//

#include "StringReverser.h"
#include <bits/stdc++.h>
using namespace std;
string StringReverser::reversme() {
    reverse(this->mystring.begin(), this->mystring.end());
    return this->mystring;
    /////
}