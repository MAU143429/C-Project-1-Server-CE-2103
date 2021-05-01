//
// Created by mau14 on 13/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H
#define PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H


#include <string>
#include "../MessageJson/JSON_Management.h"
#include "../Memory Management/Memory_Map.h"


using namespace std;

class Search_Type {

public:
    /**
     * @brief Searches for the datatype on the memory map.
     * @param jsonString
     * @return string
     */
    static string Search_DataType(const string &jsonString){
        auto response = new Response();
        string name = JSON_Management::GetJSONString("name", jsonString);

        if(Memory_Map::getInstance()->Search_Name(name)){
            string type = Memory_Map::getInstance()->Get_Type(name);
            if(type == "Integer"){
                response->setPrint(Memory_Management::getInstance()->Get_mallocvalue<int>(Memory_Map::getInstance()->Get_Offset(name)));
                response->setValue(Memory_Management::getInstance()->Get_mallocvalue<int>(Memory_Map::getInstance()->Get_Offset(name)));
            }else if(type == "Float"){
                response->setPrint(Memory_Management::getInstance()->Get_mallocvalue<float>(Memory_Map::getInstance()->Get_Offset(name)));
                response->setValue(Memory_Management::getInstance()->Get_mallocvalue<float>(Memory_Map::getInstance()->Get_Offset(name)));
            }else if(type == "Double"){
                response->setPrint(Memory_Management::getInstance()->Get_mallocvalue<double>(Memory_Map::getInstance()->Get_Offset(name)));
                response->setValue(Memory_Management::getInstance()->Get_mallocvalue<double>(Memory_Map::getInstance()->Get_Offset(name)));
            }else if(type == "Long") {
                response->setPrint(Memory_Management::getInstance()->Get_mallocvalue<long>(Memory_Map::getInstance()->Get_Offset(name)));
                response->setValue(Memory_Management::getInstance()->Get_mallocvalue<long>(Memory_Map::getInstance()->Get_Offset(name)));
            }else if(type == "Char") {
                response->setPrint(Memory_Management::getInstance()->Get_mallocvalue<char>(Memory_Map::getInstance()->Get_Offset(name)));
                response->setValue(Memory_Management::getInstance()->Get_mallocvalue<char>(Memory_Map::getInstance()->Get_Offset(name)));
            }
            response->setType(type);
            response->setName(name);
            response->setCode("100");
            response->setResponse("LA VARIABLE SE HA PRINTEADO CON EXITO");
            cout<<"SI EXISTE LA VARIABLE CONSULTADA"<< endl;
            return JSON_Management::NewResponseToJSON(response);


        }else{
            cout<<"NO EXISTE LA VARIABLE CONSULTADA"<< endl;
        };

    }


};


#endif //PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H
