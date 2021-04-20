#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "src/TypeConversion/JSON_Management.h"
#include "src/Convert_message/Convert_request.h"
#include "src/MM/Memory_Management.h"


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
    message1->setName("Naheem");
    message1->setAction("CREATE");
    message1->setType("Float");
    message1->setValue("5.345");
    message1->setSize("4");

    string newsms = JSON_Management::NewMessageToJSON(message);
    string newsms1 = JSON_Management::NewMessageToJSON(message1);

    JSON_Management::GetJSONString("action",newsms);
    JSON_Management::GetJSONString("action",newsms1);
    Convert_request::Select_Type_Message(newsms);
    Convert_request::Select_Type_Message(newsms1);






    return 0;
}
