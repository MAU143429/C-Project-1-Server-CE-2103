//
// Created by njohnson on 3/30/21.
//

#ifndef C_IDE_CHAR_H
#define C_IDE_CHAR_H
#include "Data_Type.h"

using namespace std;

class Char: public Data_Type {

public:
    char charvalue;

    char getChaarvalue() const {
        return charvalue;
    }

    void setChaarvalue(char chaarvalue) {
        Char::charvalue = chaarvalue;
    }

    Char(string name, const char *value){
        this->name = name;
        this->charvalue = Convert_Value::classify_type<char>("Char", value);
        this->ref_count = 0;
        this->size = 1;
        this->value_address = Memory_Management::getInstance()->appendElem(charvalue);
        this->type = "Char";
        cout << "Se creo un objeto char de nombre" << this->name << "con un valor de" << this->charvalue << " almacenado en el offset numero " << value_address << endl;

    };

};


#endif //C_IDE_CHAR_H
