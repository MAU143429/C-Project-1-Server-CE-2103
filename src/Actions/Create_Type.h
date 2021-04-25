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
#include "../MessageJson/JSON_Management.h"
#include "../Data_Types/Integer.h"
#include "../Data_Types/Long.h"
#include "../Data_Types/Float.h"
#include "../Data_Types/Double.h"
#include "../Data_Types/Char.h"
#include "../Memory Management/Memory_Map.h"
#include "Modify_Type.h"


using namespace std;

static const auto SUM_OPERATOR = "+";
static const auto SUBTRAC_OPERATOR = "-";
static const auto DIV_OPERATOR = "/";
static const auto MULTI_OPERATOR = "*";

static SimplyList<string> *Operator_list;
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
    template <typename T>
    static T Create_DataType(const string &jsonString){
        auto response = new Response();
        string type = JSON_Management::GetJSONString("type", jsonString);
        string name = JSON_Management::GetJSONString("name", jsonString);
        string num = JSON_Management::GetJSONString("value", jsonString);


        if(!Memory_Map::getInstance()->Search_Name(name)){

            if(type == "Integer"){
                auto createint = Integer(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createint);
            }else if(type == "Long"){
                auto createlong = Long(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createlong);

            }else if(type == "Float"){
                auto createfloat = Float(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createfloat);


            }else if(type == "Double"){
                auto createdouble = Double(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createdouble);

            }else if(type == "Char"){
                auto createchar = Char(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createchar);


            }
        }else{
            //TODO CREAR EL RESPONSE DE QUE LA VARIABLE YA ESTA EN USO CODIGO 101
            cout <<"ERROR:EL NOMBRE DE LA VARIABLE QUE DESEAS CREAR YA ESTA EN USO"<<endl;
            response->setCode("101");
            response->setResponse("ERROR:EL NOMBRE DE LA VARIABLE QUE DESEAS CREAR YA ESTA EN USO");
            return JSON_Management::NewResponseToJSON(response);

        }

    }



};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CREATE_TYPE_H
