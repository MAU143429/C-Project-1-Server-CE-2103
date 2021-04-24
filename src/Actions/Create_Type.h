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
#include "../Socket/Server.h"

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

        string type = JSON_Management::GetJSONString("type", jsonString);
        string name = JSON_Management::GetJSONString("name", jsonString);
        string num = JSON_Management::GetJSONString("value", jsonString);

        cout<<"VOY A ENTRAR A LA CONDICION DEL NOMBRE"<<endl;
        if(!Memory_Map::getInstance()->Search_Name(name)){
            auto created = new Response();
            created->setResponse("SE HA CREADO LA VARIABLE CON EXITO!");
            created->setCode("102");


            cout<<"ENTRE PORQUE SOY DIFERENTE"<<endl;
            if(type == "Integer"){
                auto createint = Integer(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createint);
                C
            }else if(type == "Long"){
                auto createlong = Long(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createlong);
                Server::getInstance()->Send(JSON_Management::NewResponseToJSON(created).c_str());
            }else if(type == "Float"){
                auto createfloat = Float(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createfloat);
                Server::getInstance()->Send(JSON_Management::NewResponseToJSON(created).c_str());
            }else if(type == "Double"){
                auto createdouble = Double(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createdouble);
                Server::getInstance()->Send(JSON_Management::NewResponseToJSON(created).c_str());
            }else if(type == "Char"){
                auto createchar = Char(JSON_Management::GetJSONString("name", jsonString),num.c_str());
                Memory_Map::getInstance()->append_list(createchar);
                Server::getInstance()->Send(JSON_Management::NewResponseToJSON(created).c_str());

            }
        }else{
            auto error = new Response();
            error->setResponse("ERROR:EL NOMBRE DE LA VARIABLE QUE DESEAS CREAR YA ESTA EN USO");
            error->setCode("101");
            Server::getInstance()->Send(JSON_Management::NewResponseToJSON(error).c_str());
        }

    }



};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CREATE_TYPE_H
