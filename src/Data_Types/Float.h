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
    /**
     * @brief constructor for the float class.
     * @param name
     * @param value
     */
    Float(string name, const char *value){
        this->floatvalue = Convert_Value::classify_type<float>("Float",value);
        this->value_address = Memory_Management::getInstance()->appendElem(floatvalue);
        this->name = name;
        this->floatvalue = Memory_Management::getInstance()->searchmalloc<float>(value_address);
        this->ref_count = 1;
        this->size = 4;
        this->type="Float";
        this->Memory_Adrr = Memory_Management::getInstance()->getMemory_Address<string>(value_address);
        cout<<"Se creo un objeto float de nombre "<< this->name << " con un valor de " << this->floatvalue <<" almacenado en el offset numero " << value_address << endl;
    }

};


#endif //C_IDE_FLOAT_H
