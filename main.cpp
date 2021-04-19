#include <iostream>
#include "src/Data_Types/Data_Type.h"
#include "src/Convert_message/Convert_request.h"
#include "src/Convert_message/TypeMessage.h"
#include "src/TypeConversion/ObjectToJSON.h"
#include "src/TypeConversion/JSON_Management.h"
#include "src/Actions/Cast_to_Type.h"


int main() {



    //This method allows to classify the data that you want to convert to a specific data type
    /**
    int varint;
    float varfloat;
    double vardouble;
    long varlong;


    string tipo = "Float";
    const char *valor = "5.678356458745874877845";

    if(tipo == "Integer"){
        varint = Cast_to_Type::Cast_int<int>(valor);
        cout<< "Ya soy entero" << varint << endl;
    }else if(tipo == "Long"){
        varlong = Cast_to_Type::Cast_long<long>(valor);
        cout<< varlong<< endl;
    }else if(tipo == "Float"){
        varfloat = Cast_to_Type::Cast_float<float>(valor);
        cout<< varfloat << endl;
    }else if(tipo == "Double"){
        vardouble = Cast_to_Type::Cast_double<double>(valor);
        cout<< vardouble << endl;
    }
    */






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
