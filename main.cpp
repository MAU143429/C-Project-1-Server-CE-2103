#include <string>
#include <thread>
#include <pthread.h>
#include "src/MessageJson/JSON_Management.h"
#include "src/Memory Management/Memory_Management.h"
#include "src/Socket/Server.h"

using namespace std;

void RunServer(int port){
    cout << "Server is running" << endl;
    Server::getInstance()->InitServer(port);

}

void main_v2(int size){
    Memory_Management::getInstance()->InitMalloc(size);
    cout<<"MALLOC SIZE IS " << size << endl;
    int port;
    string userInput;
    cout<< "Define the port of the server: " ;
    getline(cin, userInput);
    port = atoi(userInput.c_str());
    thread runs (RunServer,port);
    runs.join();
}
int main() {
    int malloc_size;
    string userInput;
    cout<< "Define the size of the malloc(bytes): " ;
    getline(cin, userInput);
    malloc_size = atoi(userInput.c_str());
    main_v2(malloc_size);

    return 0;
}
