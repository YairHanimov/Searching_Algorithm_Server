#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto *ch = new MyTestClientHandler();
    auto *a = new MySerialServer();
    a->open(5600, (MyTestClientHandler)*ch);
    string strtest="hello world";
    StringReverser *rev=new StringReverser(strtest);
    cout<<rev->reversme()<<endl;
    return 0;
}