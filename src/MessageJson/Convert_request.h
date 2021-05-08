//
// Created by mau14 on 14/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__CONVERT_REQUEST_H
#define PROYECTO_1_DATOS_II_SERVER_C__CONVERT_REQUEST_H

#include "JSON_Management.h"
#include "istream"
#include "../Actions/Modify_Type.h"
#include "../Actions/Create_Type.h"
#include "../Actions/Search_Type.h"


using namespace std;
class Convert_request {

public:
    /**
     * @brief Receives a key and identifies it between a create, modify or search type of action.
     * @param jsonString the json containing the message sent from the client.
     * @return a string containing the response that needs to be sent to the client.
     */
    static string Select_Type_Message(const string &jsonString) {
        string verify;
        string message = JSON_Management::GetJSONString("action", jsonString);
        auto response = new Response();
        if (message == "CREATE") {
            verify = Create_Type::Create_DataType<string>(jsonString);
            if (verify.empty()){
                string varname = JSON_Management::GetJSONString("name", jsonString);


                response->setCode("100");
                response->setResponse("EL SERVIDOR HA CREADO LA VARIABLE CON EXITO");
                response->setName(JSON_Management::GetJSONString("name",jsonString));
                response->setValue(JSON_Management::GetJSONString("value",jsonString));
                response->setMemoryAddress(Memory_Map::getInstance()->Get_MemoryAddress(JSON_Management::GetJSONString("name",jsonString)));
                response->setRefCount(Memory_Map::getInstance()->Get_RefCount(JSON_Management::GetJSONString("name",jsonString)));
                response->setPrint("1");
                return JSON_Management::NewResponseToJSON(response);
            }else{
                return verify;
            }


        } else if (message == "MODIFY") {
            cout << "SOY UN ARCHIVO AL QUE VAN A MODIFICAR" << endl;
            Modify_Type::Modify_Datatype<string>(jsonString);
            response->setCode("100");
            response->setResponse("EL SERVIDOR HA MODIFICADO LA VARIABLE CON EXITO");
            response->setName(JSON_Management::GetJSONString("name",jsonString));
            response->setPrint("1");

            if(Memory_Map::getInstance()->Get_Type(JSON_Management::GetJSONString("name",jsonString)) == "Char"){
                string char1;
                char1 = JSON_Management::GetJSONString("modifyvalue",jsonString)[1];
                response->setValue(char1);
            }else{
                response->setValue(JSON_Management::GetJSONString("modifyvalue",jsonString));
            }
            response->setMemoryAddress(Memory_Map::getInstance()->Get_MemoryAddress(JSON_Management::GetJSONString("name",jsonString)));
            response->setRefCount(Memory_Map::getInstance()->Get_RefCount(JSON_Management::GetJSONString("name",jsonString)));

            return JSON_Management::NewResponseToJSON(response);

        } else if (message == "SEARCH") {
            cout << "SOY UN ARCHIVO AL QUE VAN A BUSCAR" << endl;
            string result = Search_Type::Search_DataType(jsonString);
            return result;
        }else if(message == "STOP"){
            Memory_Map::getInstance()->Save_Info();
            response->setCode("102");
            response->setResponse("EL SERVIDOR HA GUARDADO LAS DIRECCIONES DE MEMORIA CON EXITO");
            return JSON_Management::NewResponseToJSON(response);

        }
    }
};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CONVERT_REQUEST_H
