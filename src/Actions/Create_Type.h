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
    /**
     * @brief Initializes the operator list.
     */
    void Init_List(){
        Operator_list = new SimplyList<string>();
        Operator_list->append(SUM_OPERATOR);
        Operator_list->append(SUBTRAC_OPERATOR);
        Operator_list->append(DIV_OPERATOR);
        Operator_list->append(MULTI_OPERATOR);
    }
    /**
     * @brief Verifies the operator.
     * @param value
     * @return a boolean.
     */
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
    /**
     * @brief Method that created a new variable in the memory map, if its already in the memory map it sends an error message to client.
     * @tparam T
     * @param jsonString
     * @return a null string or a string containing the response.
     */
    template <typename T>
    static T Create_DataType(const string &jsonString){
        auto response = new Response();
        string type = JSON_Management::GetJSONString("type", jsonString);
        string name = JSON_Management::GetJSONString("name", jsonString);
        string num = JSON_Management::GetJSONString("value", jsonString);


        if(!Memory_Map::getInstance()->Search_Name(name)){
            if(type == "Integer"){
                auto createint = Integer(name,num.c_str());
                Memory_Map::getInstance()->append_list(createint);
                return "";
            }else if(type == "Long"){
                auto createlong = Long(name,num.c_str());
                Memory_Map::getInstance()->append_list(createlong);
                return "";
            }else if(type == "Float"){
                auto createfloat = Float(name,num.c_str());
                Memory_Map::getInstance()->append_list(createfloat);
                return "";

            }else if(type == "Double"){
                auto createdouble = Double(name,num.c_str());
                Memory_Map::getInstance()->append_list(createdouble);
                return "";
            }else if(type == "Char"){
                auto createchar = Char(name,num.c_str());
                Memory_Map::getInstance()->append_list(createchar);
                return "";
            }
        }else{

            response->setCode("101");
            response->setResponse("ERROR:EL NOMBRE DE LA VARIABLE QUE DESEAS CREAR YA ESTA EN USO");
            return JSON_Management::NewResponseToJSON(response);

        }

    }



};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CREATE_TYPE_H
