//
// Created by mau14 on 13/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__MODIFY_TYPE_H
#define PROYECTO_1_DATOS_II_SERVER_C__MODIFY_TYPE_H

#include "string"
#include "iostream"
#include "../MessageJson/JSON_Management.h"
#include "../Memory Management/Memory_Map.h"
#include "../Actions/Cast_to_Type.h"
#include "../Actions/Convert_Value.h"


using namespace std;

class Modify_Type {

public:
    /**
     * @brief Method that searches for a created data in memory map and modifies it.
     * @tparam T
     * @param jsonString
     * @return a boolean
     */
    template<typename T>
    static bool Modify_Datatype(const string &jsonString){

        string name = JSON_Management::GetJSONString("name", jsonString);
        string newnum =JSON_Management::GetJSONString("modifyvalue", jsonString);
        string type = Memory_Map::getInstance()->Get_Type(name);



        int varint;
        long varlong;
        float varfloat;
        double vardouble;
        char varchar;

        if(type == "Integer"){
            varint = Cast_to_Type::Cast_int<int>(newnum.c_str());
            Memory_Map::getInstance()->template Modify_Value(name,type,varint);


        }else if(type == "Long"){
            varlong = Cast_to_Type::Cast_long<long>(newnum.c_str());
            Memory_Map::getInstance()->template Modify_Value(name,type,varlong);



        }else if(type == "Float"){
            varfloat = Cast_to_Type::Cast_float<float>(newnum.c_str());
            Memory_Map::getInstance()->template Modify_Value(name,type,varfloat);


        }else if(type == "Double"){
            vardouble = Cast_to_Type::Cast_double<double>(newnum.c_str());
            Memory_Map::getInstance()->template Modify_Value(name,type,vardouble);


        }else if(type == "Char"){
            varchar = Cast_to_Type::Cast_char<char>(newnum.c_str());
            Memory_Map::getInstance()->template Modify_Value(name,type,varchar);


        }
    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__MODIFY_TYPE_H
