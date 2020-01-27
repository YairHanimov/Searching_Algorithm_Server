#include <iostream>
#include "MyParallelServer.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"

using namespace std;

int main(int argc, char **argv) {

    int port;
    if(argc == 2) {
        char *inputPort = argv[1]; // get the port
        port = atoi(inputPort);
    }
    else {
        port = 5600;
    }
//    part two
//    auto *cm = new FileCacheManager<string,string>();
//    auto *s = new StringReverser();
//    auto *ch = new MyTestClientHandler<string,string>(cm, s);
//    MySerialServer *serial_server = new MySerialServer(5600, ch);
//    serial_server->open();

    //part three
    auto *cm = new FileCacheManager<string, string>();
    auto *ch = new MyClientHandler<string, string>(cm);
    //ch->handleClient(1,1);
    auto *pm = new MyParallelServer(port, ch);
    pm->open();
    //ch->handleClient(1,1);
    //MySerialServer *serial_server = new MySerialServer(5600, ch);
    //serial_server->open();
    return 0;
}