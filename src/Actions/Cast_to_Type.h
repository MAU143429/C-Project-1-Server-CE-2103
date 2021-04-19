//
// Created by mau14 on 14/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__CAST_TO_TYPE_H
#define PROYECTO_1_DATOS_II_SERVER_C__CAST_TO_TYPE_H

#include "iostream"
#include "sstream"
#include "stdlib.h"
#include "../Data_Types/Data_Type.h"
#include "../Data_Types/SimplyList.h"
using namespace std;


class Cast_to_Type {

public:
    template <typename T>
    T Cast_Type(const char *value){

        if( T ){
            return atoi(value);
        }else if(T<long> == long){
            return atol(value);

        }else if(T<float> == float){
            return atof(value);

        }else if(T<double> == double){
            return atof(value);

        }else if(T<char> == char){
            return *value;
        }
    }



};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CAST_TO_TYPE_H
