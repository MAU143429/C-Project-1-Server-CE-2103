//
// Created by njohnson on 4/1/21.
//

#ifndef C_IDE_OBJECTTOJSON_H
#define C_IDE_OBJECTTOJSON_H
#include "../../lib/rapidjson/stringbuffer.h"
#include "../../lib/rapidjson/writer.h"
#include <string>
#include "iostream"


using namespace rapidjson;
using namespace std;

class ObjectToJSON{
public:
    string static NewMessageToJSON(TypeMessage *message){
        const string& action = message->getAction();
        const string& type = message->getType();
        const string& size = message->getSize();
        const string& name = message->getName();
        const string& value = message->getValue();


        StringBuffer stringBuffer;
        Writer<StringBuffer> writer(stringBuffer);
        writer.StartObject();

        writer.Key("action");
        writer.String(action.c_str());

        writer.Key("type");
        writer.String(type.c_str());

        writer.Key("size");
        writer.String(size.c_str());

        writer.Key("name");
        writer.String(name.c_str());

        writer.Key("value");
        writer.String(value.c_str());


        writer.EndObject();
        cout << stringBuffer.GetString() << endl;
        return stringBuffer.GetString();
    }

};
#endif //C_IDE_OBJECTTOJSON_H
