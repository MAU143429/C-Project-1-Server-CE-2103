//
// Created by mau14 on 13/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__CREATE_TYPE_H
#define PROYECTO_1_DATOS_II_SERVER_C__CREATE_TYPE_H

#include "istream"
#include "sstream"
#include "Cast_to_Type.h"
#include "stdlib.h"
#include "../Data_Types/Data_Type.h"
#include "../Data_Types/SimplyList.h"
using namespace std;

static const auto SUM_OPERATOR = "+";
static const auto SUBTRAC_OPERATOR = "-";
static const auto DIV_OPERATOR = "/";
static const auto MULTI_OPERATOR = "*";

static SimplyList<string> *Operator_list;
template <typename T>
class Create_Type {

public:
    void Init_List(){
        Operator_list = new SimplyList<string>();
        Operator_list->append(SUM_OPERATOR);
        Operator_list->append(SUBTRAC_OPERATOR);
        Operator_list->append(DIV_OPERATOR);
        Operator_list->append(MULTI_OPERATOR);
    }

    static bool Operator_Verify(string value){
        std::stringstream mm;
        int counter1 = 0;
        char character1;
        string output;

        while (counter1 < value.length()) {
            character1 = value[counter1];
            mm << character1;
            mm >> output;
            if (Operator_list->Search(output)) {
                return true;
            } else {
                output.clear();
                mm.clear();
            }
            counter1++;
        }
        return false;
    }

    string Create_DataType(T element){


        //TODO Entra objeto de tipo DataType para ser creado
    }



};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CREATE_TYPE_H
