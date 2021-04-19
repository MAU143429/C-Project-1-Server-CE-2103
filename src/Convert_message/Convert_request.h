//
// Created by mau14 on 14/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__CONVERT_REQUEST_H
#define PROYECTO_1_DATOS_II_SERVER_C__CONVERT_REQUEST_H

#include "../TypeConversion/JSON_Management.h"
#include "istream"
#include "../Actions/Create_Type.h"
#include "../Actions/Modify_Type.h"
#include "../Actions/Search_Type.h"
#include "../Data_Types/Integer.h"
#include "../Data_Types/Float.h"
#include "../Data_Types/Double.h"
#include "../Data_Types/Char.h"
#include "../Data_Types/Long.h"

using namespace std;
class Convert_request {

public:
    static void Select_Type_Message(const string &jsonString) {

        string message = JSON_Management::GetJSONString("action", jsonString);
        string message2 = JSON_Management::GetJSONString("type", jsonString);
        string num = JSON_Management::GetJSONString("value", jsonString);

        if (message == "CREATE") {

            if(message2 == "Integer"){
                auto createint = Integer(JSON_Management::GetJSONString("name", jsonString),num.c_str());
            }else if(message2 == "Long"){
                auto createlong = Long(JSON_Management::GetJSONString("name", jsonString),num.c_str());
            }else if(message2 == "Float"){
                auto createfloat = Float(JSON_Management::GetJSONString("name", jsonString),num.c_str());
            }else if(message2 == "Double"){
                auto createdouble = Double(JSON_Management::GetJSONString("name", jsonString),num.c_str());
            }else if(message2 == "Char"){
                auto createchar = Char(JSON_Management::GetJSONString("name", jsonString),num.c_str());
            }

        } else if (message == "MODIFY") {
            cout << "SOY UN ARCHIVO AL QUE VAN A MODIFICAR" << endl;
        } else if (message == "SEARCH") {
            cout << "SOY UN ARCHIVO AL QUE VAN A BUSCAR" << endl;
        }
    }
};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CONVERT_REQUEST_H
