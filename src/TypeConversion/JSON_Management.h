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
#include "../Convert_message/TypeMessage.h"
#include "../Data_Types/Response.h"

#include <string>
#include "iostream"
#include "../Data_Types/RamLV.h"

using namespace rapidjson;
using namespace std;

class JSON_Management{
public:
    static string NewDatatypeToJSON(Data_Type *dataType){

        StringBuffer stringBuffer;
        Writer<StringBuffer> writer(stringBuffer);
        writer.StartObject();

        if (!dataType->getName().empty()){
            writer.Key("name");
            writer.String(dataType->getName().c_str());
        } else{
            writer.Key("name");
            writer.Null();
        }

        if (dataType->getValue() != nullptr){
            writer.Key("value");
            writer.String(dataType->getValue());
        } else{
            writer.Key("value");
            writer.Null();
        }

        if (dataType->getSize() != 0){
            writer.Key("size");
            writer.Int(dataType->getSize());
        }else{
            writer.Key("size");
            writer.Null();
        }

        if (dataType->getRefCount() != 0){
            writer.Key("ref_count");
            writer.Int(dataType->getRefCount());
        }else{
            writer.Key("ref_count");
            writer.Null();
        }

        if (dataType->getValueAddress() != 0){
            writer.Key("value_address");
            writer.Int(dataType->getValueAddress());
        }else{
            writer.Key("value_address");
            writer.Null();
        }

        writer.EndObject();
        cout << stringBuffer.GetString() << endl;
        return stringBuffer.GetString();
    }
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
            int ref_ptr = value_address;
            dataType->setValueAddress(ref_ptr);
        }

        return dataType;
    }

    static string NewMessageToJSON(TypeMessage *message){
        const string& action = message->getAction();
        const string& response = message->getResponse();
        const string& type = message->getType();
        const string& size = message->getSize();
        const string& name = message->getName();
        const string& value = message->getValue();
        const string& modifyvalue = message->getModifyvalue();


        StringBuffer stringBuffer;
        Writer<StringBuffer> writer(stringBuffer);
        writer.StartObject();

        writer.Key("action");
        writer.String(action.c_str());

        writer.Key("response");
        writer.String(response.c_str());

        writer.Key("type");
        writer.String(type.c_str());

        writer.Key("size");
        writer.String(size.c_str());

        writer.Key("name");
        writer.String(name.c_str());

        writer.Key("value");
        writer.String(value.c_str());

        writer.Key("modifyvalue");
        writer.String(modifyvalue.c_str());



        writer.EndObject();
        cout << stringBuffer.GetString() << endl;
        return stringBuffer.GetString();
    }

    static string NewResponseToJSON(Response *response){
        StringBuffer stringBuffer;
        Writer<StringBuffer> writer(stringBuffer);
        writer.StartObject();

        if (!response->getResponse().empty()){
            writer.Key("response");
            writer.String(response->getResponse().c_str());
        } else{
            writer.Key("response");
            writer.Null();
        }

        if (!response->getCode().empty()){
            writer.Key("code");
            writer.String(response->getCode().c_str());
        } else{
            writer.Key("code");
            writer.Null();
        }



        writer.EndObject();
        cout << stringBuffer.GetString() << endl;
        return stringBuffer.GetString();
    }

    static string NewRamLVToJSON(RamLV *ramobject){
        StringBuffer stringBuffer;
        Writer<StringBuffer> writer(stringBuffer);
        writer.StartObject();

        if (!ramobject->getMemoryAddr().empty()){
            writer.Key("memory_address");
            writer.String(ramobject->getMemoryAddr().c_str());
        } else{
            writer.Key("memory_address");
            writer.Null();
        }

        if (!ramobject->getValue().empty()){
            writer.Key("value");
            writer.String(ramobject->getValue().c_str());
        } else{
            writer.Key("value");
            writer.Null();
        }

        if (!ramobject->getName().empty()){
            writer.Key("name");
            writer.String(ramobject->getName().c_str());
        } else{
            writer.Key("name");
            writer.Null();
        }

        if (!ramobject->getRefCounter().empty()){
            writer.Key("reference_counter");
            writer.String(ramobject->getRefCounter().c_str());
        } else{
            writer.Key("reference_counter");
            writer.Null();
        }

        writer.EndObject();
        cout << stringBuffer.GetString() << endl;
        return stringBuffer.GetString();
    }

    string static GetJSONString(string key, const string &jsonString){
        rapidjson::Document document;
        document.Parse<kParseDefaultFlags>(jsonString.c_str());
        const char *searchedString;
        if (document.HasMember(key.c_str())){
            if (document[key.c_str()].IsString()){
                searchedString = document[key.c_str()].GetString();

            }
            return searchedString;
        }else {
            cout << "key not found" << endl;

        }
    }

};
#endif //PROYECTO_1_DATOS_II_SERVER_C__JSON_MANAGEMENT_H
