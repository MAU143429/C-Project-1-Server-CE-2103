//
// Created by mau14 on 13/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H
#define PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H

#include "string"
#include "iostream"
#include "../TypeConversion/JSON_Management.h"
#include "../MM/Memory_Map.h"


using namespace std;

class Search_Type {

public:

    static bool Search_DataType(const string &jsonString){

        string type = JSON_Management::GetJSONString("type", jsonString);
        string name = JSON_Management::GetJSONString("name", jsonString);

        if(Memory_Map::getInstance()->BoolSearch(name,type)){
            cout<<"SI EXISTE LA VARIABLE CONSULTADA"<< endl;
            return true;
        }else{
            cout<<"NO EXISTE LA VARIABLE CONSULTADA"<< endl;
            return false;
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
