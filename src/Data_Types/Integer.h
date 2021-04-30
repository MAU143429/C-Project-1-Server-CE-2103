//
// Created by njohnson on 3/30/21.

#ifndef C_IDE_INTEGER_H
#define C_IDE_INTEGER_H
#include <string>
#include "Data_Type.h"
#include "../Actions/Convert_Value.h"
#include "../Memory Management/Memory_Management.h"



using namespace std;

class Integer: public Data_Type {

public:
    int intvalue;


    int getIntvalue() const {
        return intvalue;
    }

    void setIntvalue(int intvalue) {
        Integer::intvalue = intvalue;
    }
    /**
     * @brief constructor for the Integer class.
     * @param name
     * @param value
     */
    Integer(string name, const char *value){
        this->intvalue = Convert_Value::classify_type<int>("Integer",value);
        this->value_address = Memory_Management::getInstance()->appendElem(intvalue);
        this->name = name;
        this->intvalue = Memory_Management::getInstance()->searchmalloc<int>(value_address);
        this->ref_count = 0;
        this->size = 4;
        this->type = "Integer";
        this->Memory_Adrr = Memory_Management::getInstance()->getMemory_Address<string>(value_address);
        cout<<"Se creo un objeto int de nombre "<< this->name << " con un valor de " << this->intvalue <<" almacenado en el offset numero " << value_address << endl;
    }

};


#endif //C_IDE_INTEGER_H
