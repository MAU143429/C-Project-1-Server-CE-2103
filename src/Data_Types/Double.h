//
// Created by njohnson on 3/30/21.
//

#ifndef C_IDE_DOUBLE_H
#define C_IDE_DOUBLE_H


#include "Data_Type.h"

using namespace std;

class Double: public Data_Type {
public:
    double doublevalue;

    double getDoublevalue() const {
        return doublevalue;
    }

    void setDoublevalue(double doublevalue) {
        Double::doublevalue = doublevalue;
    }

    Double(string name, const char *value){
        this->name = name;
        this->doublevalue = Convert_Value::classify_type<double>("Double",value);
        this->ref_count = 0;
        this->size = 8;
        this->value_address = 0;
        this->type="Double";
        cout<<"Se creo un objeto double de nombre"<< this->name << "con un valor de" << this->doublevalue << endl;
    }

};


#endif //C_IDE_DOUBLE_H
