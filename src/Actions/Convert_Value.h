//
// Created by mau14 on 18/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__CONVERT_VALUE_H
#define PROYECTO_1_DATOS_II_SERVER_C__CONVERT_VALUE_H
#include "iostream"
#include "sstream"
#include "Cast_to_Type.h"
#include "stdlib.h"

using namespace std;

class Convert_Value {

public:

    template <typename T>
    static T classify_type(string type,const char *value){

        int varint;
        float varfloat;
        double vardouble;
        long varlong;
        char varchar;

        if(type == "Integer"){
            varint = Cast_to_Type::Cast_int<int>(value);
            cout<< "Ya soy entero" << varint << endl;
        }else if(type == "Long"){
            varlong = Cast_to_Type::Cast_long<long>(value);
            cout<< varlong<< endl;
        }else if(type == "Float"){
            varfloat = Cast_to_Type::Cast_float<float>(value);
            cout<< varfloat << endl;
        }else if(type == "Double"){
            vardouble = Cast_to_Type::Cast_double<double>(value);
            cout<< vardouble << endl;
        }else if(type == "Char"){
            varchar = Cast_to_Type::Cast_char<char>(value);
            cout << varchar << endl;
        }


    }




};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CONVERT_VALUE_H
