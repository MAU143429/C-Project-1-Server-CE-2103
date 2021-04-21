#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <thread>
#include "src/TypeConversion/JSON_Management.h"
#include "src/Convert_message/Convert_request.h"
#include "src/MM/Memory_Management.h"
#include "src/Socket/Server.h"

using namespace std;

int main() {




    Memory_Management::getInstance()->InitMalloc(10000);
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
    Convert_request::Select_Type_Message(newsms2);








    return 0;
}
