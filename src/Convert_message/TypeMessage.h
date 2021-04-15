//
// Created by njohnson on 4/14/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__TYPEMESSAGE_H
#define PROYECTO_1_DATOS_II_SERVER_C__TYPEMESSAGE_H
#include <string>

using namespace std;
class TypeMessage {
public:
    string type;
    string modifyValue;
    string action;
    string name;
    string value;
    string size;

    const string &getType() const;

    void setType(const string &type);

    const string &getModifyValue() const;

    void setModifyValue(const string &modifyValue);

    const string &getAction() const;

    void setAction(const string &action);

    const string &getName() const;

    void setName(const string &name);

    const string &getValue() const;

    void setValue(const string &value);

    const string &getSize() const;

    void setSize(const string &size);

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__TYPEMESSAGE_H
