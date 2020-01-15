#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

using namespace std;

int main() {
    auto *ch = new MyTestClientHandler();
    FileCacheManager<string,string> *cm ();
    auto *a = new MySerialServer(ch, cm);
    //  a->open(5600, (MyTestClientHandler)*ch);
    string strtest = "hello world";

    StringReverser *rev = new StringReverser();

    cout << rev->solve(strtest) << endl;
    return 0;
}