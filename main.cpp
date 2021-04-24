#include <string>
#include <thread>
#include <pthread.h>
#include "src/MessageJson/JSON_Management.h"
#include "src/Memory Management/Memory_Management.h"
#include "src/Socket/Server.h"

using namespace std;

void RunServer(){
    cout << "Server is running" << endl;
    Server::getInstance()->InitServer();

}

int main() {
    Memory_Management::getInstance()->InitMalloc(10000);

    thread runs (RunServer);

    runs.join();

    return 0;
}
