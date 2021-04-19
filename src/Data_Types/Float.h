//
// Created by njohnson on 3/30/21.
//

#ifndef C_IDE_FLOAT_H
#define C_IDE_FLOAT_H


#include "Data_Type.h"

using namespace std;

class Float: public Data_Type {

public:
    float floatvalue;

    float getFloatvalue() const {
        return floatvalue;
    }

    void setFloatvalue(float floatvalue) {
        Float::floatvalue = floatvalue;
    }

    Float(string name, const char *value){
        this->name = name;
        this->floatvalue = Convert_Value::classify_type<float >("Float",value);
        this->ref_count = 0;
        this->size = 4;
        this->value_address = 0;
        this->type="Float";

        cout<<"Se creo un objeto float de nombre"<< this->name << "con un valor de" << this->floatvalue << endl;
    }

};


#endif //C_IDE_FLOAT_H
