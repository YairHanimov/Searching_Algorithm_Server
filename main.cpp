#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto *ch = new MyTestClientHandler();
    auto *a = new MySerialServer();
    a->open(5600, (MyTestClientHandler)*ch);
    return 0;
}