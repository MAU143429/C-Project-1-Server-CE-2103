#include <iostream>
#include "src/Data_Types/Data_Type.h"
#include "src/Convert_message/Convert_request.h"
#include "src/Convert_message/TypeMessage.h"
#include "src/TypeConversion/ObjectToJSON.h"
#include "src/TypeConversion/JSON_Management.h"
#include "src/Actions/Cast_to_Type.h"
#include "src/Actions/Convert_Value.h"


int main() {

    string change = "Char";
    const char *valor = "B";

    Convert_Value::classify_type<char>(change,valor);


    /**
    auto *message = new TypeMessage();
    message->setName("suma");
    message->setModifyValue("23");
    message->setSize("8");
    message->setValue("14");
    message->setAction("CREATE");
    message->setType("Integer");
    


    string newsms = ObjectToJSON::NewMessageToJSON(message);
    //JSON_Management::GetJSONKey("action",newsms);
    //Convert_request::Select_Type_Message(newsms);
*/
    return 0;

}
