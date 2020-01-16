#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
using namespace std;

int main() {
    auto *cm = new FileCacheManager<string,string>();
    auto *ch = new MyTestClientHandler<string,string>(cm);
    MySerialServer<string,string> *serial_server = new MySerialServer<string,string>(5600, ch);
    //  a->open(5600, (MyTestClientHandler)*ch);
    string strtest = "hello world";

    StringReverser *rev = new StringReverser();

    cout << rev->solve(strtest) << endl;
    return 0;
}