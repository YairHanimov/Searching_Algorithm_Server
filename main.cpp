#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"

using namespace std;

int main() {
//    part two
//    auto *cm = new FileCacheManager<string,string>();
//    auto *s = new StringReverser();
//    auto *ch = new MyTestClientHandler<string,string>(cm, s);
//    MySerialServer *serial_server = new MySerialServer(5600, ch);
//    serial_server->open();

    //part three

//    string line1 = "1,2,3,4";
//    string line2 = "5,6,7,8";
//    string line3 = "9,10,11,12";
//    string line4 = "13,14,15,16";
//    vector<string> m = {line1,line2,line3,line4};
//    vector<int> enter = {0,0};
//    vector<int> exit = {3,3};
//
    auto *cm = new FileCacheManager<string,string>();
    auto *s = new StringReverser();
    auto *ch = new MyClientHandler<string,string>(cm,s);
    ch->handleClient(1,1);
    //MySerialServer *serial_server = new MySerialServer(5600, ch);
    //serial_server->open();
    return 0;
}