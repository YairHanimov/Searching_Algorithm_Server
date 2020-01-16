#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

using namespace std;

int main() {
    auto *cm = new FileCacheManager<string,string>();
    auto *ch = new MyTestClientHandler<string,string>(cm);
    MySerialServer *serial_server = new MySerialServer(5600, ch);
    serial_server->open();

    return 0;
}