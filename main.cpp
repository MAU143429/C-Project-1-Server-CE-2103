#include <string>
#include <thread>
#include <pthread.h>
#include "src/MessageJson/JSON_Management.h"
#include "src/MessageJson/Convert_request.h"
#include "src/Memory Management/Memory_Management.h"
#include "src/Socket/Server.h"

using namespace std;
int count = 0;
string leido = " ";

void RunServer(){

    cout << "Server is running" << endl;
    Server::getInstance()->InitServer();

}

void InitMemory(){
    cout << "Program is running!" << endl;
    Memory_Management::getInstance()->InitMalloc(10000);
    while(true){
        if(Server::getInstance()->client_message.size() > 1 and Server::getInstance()->client_message != leido){
            Convert_request::Select_Type_Message(Server::getInstance()->client_message);
            leido = Server::getInstance()->client_message;



        }else{
            Server::getInstance()->client_message.empty();

        }
    }

}

int main() {
    /**
    auto message = new TypeMessage();
    message->setName("Mau");
    message->setAction("CREATE");
    message->setType("Integer");
    message->setValue("5236");
    message->setSize("4");

    auto message1 = new TypeMessage();
    message1->setName("Mau");
    message1->setAction("MODIFY");
    message1->setType("Integer");
    message1->setModifyvalue("14");
    message1->setSize("4");

    auto message2 = new TypeMessage();
    message2->setName("Naheem");
    message2->setAction("SEARCH");
    message2->setType("Integer");


    string newsms = JSON_Management::NewMessageToJSON(message);
    string newsms1 = JSON_Management::NewMessageToJSON(message1);
    string newsms2 = JSON_Management::NewMessageToJSON(message2);


    Convert_request::Select_Type_Message(newsms);
    Convert_request::Select_Type_Message(newsms1);
    Convert_request::Select_Type_Message(newsms2);*/


    thread runs (RunServer);
    thread program (InitMemory);


    runs.join();
    program.join();



    return 0;
}
