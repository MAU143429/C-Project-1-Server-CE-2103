//
// Created by njohnson on 3/30/21.
//

#ifndef C_IDE_CHAR_H
#define C_IDE_CHAR_H
#include "Data_Type.h"

using namespace std;

class Char: public Data_Type {


public:

    Char(string name, const char *value){
        this->name = name;
        this->value = value;
        this->ref_count = 0;
        this->size = 1;
        this->value_address = nullptr;


    };

};


#endif //C_IDE_CHAR_H
