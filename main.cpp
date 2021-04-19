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

    string newsms = JSON_Management::NewMessageToJSON(message);

    JSON_Management::GetJSONString("action",newsms);
    Convert_request::Select_Type_Message(newsms);






    return 0;
}
