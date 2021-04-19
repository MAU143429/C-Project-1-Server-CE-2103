#include <iostream>
#include "src/Data_Types/Data_Type.h"
#include "src/Convert_message/Convert_request.h"
#include "src/Convert_message/TypeMessage.h"
#include "src/TypeConversion/ObjectToJSON.h"
#include "src/TypeConversion/JSON_Management.h"
#include "src/Actions/Cast_to_Type.h"


int main() {

    string tipo = "Integer";
    const char *valor = "1234";

    if(tipo == "Integer"){
        Cast_to_Type::Cast_Type<int>(valor);
    }else if(tipo == "Long"){
        Cast_to_Type::Cast_Type<long>(valor);

    }else if(tipo == "Float"){
        Cast_to_Type::Cast_Type<float>(valor);

    }else if(tipo == "Double"){
        Cast_to_Type::Cast_Type<double>(valor);

    }else if(tipo == "Char"){
        Cast_to_Type::Cast_Type<char>(valor);
    }







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
