//
// Created by njohnson on 4/13/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__JSON_MANAGEMENT_H
#define PROYECTO_1_DATOS_II_SERVER_C__JSON_MANAGEMENT_H

#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include "../../lib/rapidjson/document.h"
#include "../Data_Types/Data_Type.h"
#include <string>

using namespace rapidjson;
using namespace std;

class JSON_Management{
public:
     static Data_Type * JSONToDataType(const string &jsonString){
        rapidjson::Document document;
        document.Parse<kParseDefaultFlags>(jsonString.c_str());
        Data_Type *dataType = new Data_Type();

        if (document.HasMember("name")){
            string name = document["name"].GetString();
            dataType->setName(name);
        }
        if (document.HasMember("value")){
            const char *value = document["value"].GetString();
            dataType->setValue(value);
        }
        if (document.HasMember("size")){
            int size = document["size"].GetInt();
            dataType->setSize(size);
        }
        if (document.HasMember("ref_count")){
            int ref_count = document["ref_count"].GetInt();
            dataType->setRefCount(ref_count);
        }
        /*
        if (document.HasMember("value_address")){
            int *ref_count = reinterpret_cast<int *>(document["value_address"].GetInt());
            dataType->setRefCount(ref_count);
        }
         */
        return dataType;
    }

    string static NewDatatypeToJSON(Data_Type *dataType){
        string name = dataType->getName();
        const char *value = dataType->getValue();
        int size = dataType->getSize();
        int ref_count = dataType->getRefCount();
        int *value_address = dataType->getValueAddress();


        StringBuffer stringBuffer;
        Writer<StringBuffer> writer(stringBuffer);
        writer.StartObject();

        writer.Key("name");
        writer.String(name.c_str());

        writer.Key("value");
        writer.String(value);

        writer.Key("size");
        writer.Int(size);

        writer.Key("ref_count");
        writer.Int(ref_count);

        /*
        writer.Key("value_address");
        writer.Int(value_address);
         */

        writer.EndObject();
        cout << stringBuffer.GetString() << endl;
        return stringBuffer.GetString();
    }
};
#endif //PROYECTO_1_DATOS_II_SERVER_C__JSON_MANAGEMENT_H
