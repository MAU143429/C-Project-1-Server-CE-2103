//
// Created by njohnson on 3/30/21.

#ifndef C_IDE_INTEGER_H
#define C_IDE_INTEGER_H
#include <string>
#include "Data_Type.h"


using namespace std;

class Integer: public Data_Type {

public:
    Integer(string name, const char *value){
        this->name = name;
        this->value = value;
        this->ref_count = 0;
        this->size = 4;
        this->value_address = nullptr;

    }

};



#endif //C_IDE_INTEGER_H
