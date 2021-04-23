//
// Created by mau14 on 13/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H
#define PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H


#include <string>
#include "../MessageJson/JSON_Management.h"
#include "../Memory Management/Memory_Map.h"
#include "../Socket/Server.h"

using namespace std;

class Search_Type {

public:

    static void Search_DataType(const string &jsonString){

        string name = JSON_Management::GetJSONString("name", jsonString);
        auto *response = new Response();
        if(Memory_Map::getInstance()->Search_Name(name)){
            response->setCode("100");
            response->setResponse("TRUE");
            Server::getInstance()->Send(JSON_Management::NewResponseToJSON(response).c_str());
            cout<<"SI EXISTE LA VARIABLE CONSULTADA"<< endl;
        }else{
            response->setCode("100");
            response->setResponse("False");
            Server::getInstance()->Send(JSON_Management::NewResponseToJSON(response).c_str());
            cout<<"NO EXISTE LA VARIABLE CONSULTADA"<< endl;

        };

    }

    template<typename T>
    static T Get_DataType(const string &jsonString){
        string type = JSON_Management::GetJSONString("type", jsonString);
        string name = JSON_Management::GetJSONString("name", jsonString);
        return Memory_Map::getInstance()->template Get_Object<string>(name,type);
    }


};


#endif //PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H
