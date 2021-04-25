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

    static void Search_DataType(const string &jsonString){

        string name = JSON_Management::GetJSONString("name", jsonString);

        if(Memory_Map::getInstance()->Search_Name(name)){
            cout<<"SI EXISTE LA VARIABLE CONSULTADA"<< endl;
        }else{
            cout<<"NO EXISTE LA VARIABLE CONSULTADA"<< endl;
        };

    }


};


#endif //PROYECTO_1_DATOS_II_SERVER_C__SEARCH_TYPE_H
