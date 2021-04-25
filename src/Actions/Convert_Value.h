//
// Created by mau14 on 18/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__CONVERT_VALUE_H
#define PROYECTO_1_DATOS_II_SERVER_C__CONVERT_VALUE_H
#include "iostream"
#include "sstream"
#include "Cast_to_Type.h"
#include <cstdlib>

using namespace std;

class Convert_Value {

public:
    /**
     * @brief Classifies the type of the entered variable using the type entered.
     * @tparam T
     * @param type
     * @param value
     * @return the created variable.
     */
    template <typename T>
    static T classify_type(const string& type,const char *value){

        int varint;
        float varfloat;
        double vardouble;
        long varlong;
        char varchar;

        if(type == "Integer"){
            varint = Cast_to_Type::Cast_int<int>(value);
            return varint;
        }else if(type == "Long"){
            varlong = Cast_to_Type::Cast_long<long>(value);
            return varlong;
        }else if(type == "Float"){
            varfloat = Cast_to_Type::Cast_float<float>(value);
            return varfloat;
        }else if(type == "Double"){
            vardouble = Cast_to_Type::Cast_double<double>(value);
            return vardouble;
        }else if(type == "Char"){
            varchar = Cast_to_Type::Cast_char<char>(value);
            return varchar;
        }


    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CONVERT_VALUE_H
