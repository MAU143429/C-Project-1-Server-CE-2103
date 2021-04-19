//
// Created by mau14 on 14/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__CAST_TO_TYPE_H
#define PROYECTO_1_DATOS_II_SERVER_C__CAST_TO_TYPE_H

#include "iostream"
#include "sstream"
#include "stdlib.h"
#include "Cast_to_Type.h"
#include "../Data_Types/Data_Type.h"
#include "../Data_Types/SimplyList.h"
using namespace std;


class Cast_to_Type {

public:
    template <typename T>
    static T Cast_int(const char *value){
            return atoi(value);
    }
    template <typename T>
    static T Cast_long(const char *value){
        return atol(value);
    }
    template <typename T>
    static T Cast_float(const char *value){
        return atof(value);
    }
    template <typename T>
    static T Cast_double(const char *value){
        return strtod(value,NULL);
    }
    template <typename T>
    static T Cast_char(const char *value){

        char varchar1;
        std::stringstream ss;
        ss << value;
        ss >> varchar1;
        return varchar1;
    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CAST_TO_TYPE_H
