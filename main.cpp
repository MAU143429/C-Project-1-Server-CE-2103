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

void main_v2(int size){
    Memory_Management::getInstance()->InitMalloc(size);
    cout<<"MALLOC SIZE IS " << size << endl;
    thread runs (RunServer);
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
