//
// Created by njohnson on 3/30/21.
//

#ifndef C_IDE_CHAR_H
#define C_IDE_CHAR_H
#include "Data_Type.h"

using namespace std;

class Char: public Data_Type {

public:
    char chaarvalue;

    char getChaarvalue() const {
        return chaarvalue;
    }

    void setChaarvalue(char chaarvalue) {
        Char::chaarvalue = chaarvalue;
    }

    Char(string name, const char *value){
        this->name = name;
        this->chaarvalue = Convert_Value::classify_type<char>("Char",value);
        this->ref_count = 0;
        this->size = 1;
        this->value_address = 0;
        this->type = "Char";
        cout<<"Se creo un objeto char de nombre"<< this->name << "con un valor de" << this->chaarvalue << endl;

    };

};


#endif //C_IDE_CHAR_H
