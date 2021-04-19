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


using namespace std;

int main() {
    auto message = new TypeMessage();
    message->setName("Mau");
    message->setAction("CREATE");

    string newsms = JSON_Management::NewMessageToJSON(message);

    JSON_Management::GetJSONString("action",newsms);
    Convert_request::Select_Type_Message(newsms);

    return 0;
}
