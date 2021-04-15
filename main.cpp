#include <iostream>
#include "src/Data_Types/Data_Type.h"
#include "src/Convert_message/Convert_request.h"
#include "src/TypeConversion/JSON_Management.h"
#include "src/Convert_message/TypeMessage.h"

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
