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
        if (message == "CREATE") {
            Create_Type::Create_DataType<string>(jsonString);
        } else if (message == "MODIFY") {
            cout << "SOY UN ARCHIVO AL QUE VAN A MODIFICAR" << endl;
        } else if (message == "SEARCH") {
            cout << "SOY UN ARCHIVO AL QUE VAN A BUSCAR" << endl;
        }
    }
};


#endif //PROYECTO_1_DATOS_II_SERVER_C__CONVERT_REQUEST_H
