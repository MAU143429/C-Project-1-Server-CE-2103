//
// Created by njohnson on 3/30/21.
//

#ifndef C_IDE_LONG_H
#define C_IDE_LONG_H


#include "Data_Type.h"

class Long: public Data_Type  {
public:

    Long(string name, const char *value){
        this->name = name;
        this->value = value;
        this->ref_count = 0;
        this->size = 8;
        this->value_address = nullptr;

    }

};


#endif //C_IDE_LONG_H
