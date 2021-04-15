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
#include "iostream"

using namespace rapidjson;
using namespace std;

class JSON_Management{
public:
     static Data_Type * JSONToDataType(const string &jsonString){
        rapidjson::Document document;
        document.Parse<kParseDefaultFlags>(jsonString.c_str());
        auto *dataType = new Data_Type();

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

        if (document.HasMember("value_address")){
            int value_address = (document["value_address"].GetInt());
            int *ref_ptr = &value_address;
            dataType->setValueAddress(ref_ptr);
        }

        return dataType;
    }
     static string GetJSONKey(string key, const string &jsonString){
        rapidjson::Document document;
        document.Parse<kParseDefaultFlags>(jsonString.c_str());

        if (document.HasMember(key.c_str())){
            const char *searchedString = document[key.c_str()].GetString();
            cout << searchedString << endl;
            return searchedString;
        }else{
            cout << "The key wasn't found!" << endl;
        }
     }

    static string NewDatatypeToJSON(Data_Type *dataType){
         
        StringBuffer stringBuffer;
        Writer<StringBuffer> writer(stringBuffer);
        writer.StartObject();

        if (!dataType->getName().empty()){
            writer.Key("name");
            writer.String(dataType->getName().c_str());
        } else{
            writer.Key("name");
            writer.String("");
        }

        if (dataType->getValue() != nullptr){
            writer.Key("value");
            writer.String(dataType->getValue());
        } else{
            writer.Key("value");
            writer.String("");
        }

        if (dataType->getSize() != 0){
            writer.Key("size");
            writer.Int(dataType->getSize());
        }else{
            writer.Key("size");
            writer.Int(0);
        }

        if (dataType->getRefCount() != 0){
            writer.Key("ref_count");
            writer.Int(dataType->getRefCount());
        }else{
            writer.Key("ref_count");
            writer.Int(0);
        }

        if (dataType->getValueAddress() != nullptr){
            writer.Key("value_address");
            writer.Int(*(dataType->getValueAddress()));
        }else{
            writer.Key("value_address");
            writer.Int(0);
        }

        writer.EndObject();
        cout << stringBuffer.GetString() << endl;
        return stringBuffer.GetString();
    }
};
#endif //PROYECTO_1_DATOS_II_SERVER_C__JSON_MANAGEMENT_H
