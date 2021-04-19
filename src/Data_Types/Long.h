//
// Created by njohnson on 3/30/21.
//

#ifndef C_IDE_LONG_H
#define C_IDE_LONG_H


#include "Data_Type.h"

class Long: public Data_Type  {
public:
    long longvar;

    long getLongvar() const {
        return longvar;
    }

    void setLongvar(long longvar) {
        Long::longvar = longvar;
    }

    Long(string name, const char *value){
        this->name = name;
        this->longvar = Convert_Value::classify_type<long>("Long",value);
        this->ref_count = 0;
        this->size = 8;
        this->value_address = nullptr;
        this->type = "Long";
        cout<<"Se creo un objeto long de nombre"<< this->name << "con un valor de" << this->longvar << endl;

    }

};


#endif //C_IDE_LONG_H
