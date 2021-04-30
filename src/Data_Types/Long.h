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
    /**
     * @brief constructor for the Long class.
     * @param name
     * @param value
     */
    Long(string name, const char *value){
        this->longvar = Convert_Value::classify_type<long>("Long",value);
        this->value_address = Memory_Management::getInstance()->appendElem(longvar);
        this->name = name;
        this->longvar = Memory_Management::getInstance()->searchmalloc<long>(value_address);
        this->ref_count = 0;
        this->size = 8;
        this->type = "Long";
        this->Memory_Adrr = Memory_Management::getInstance()->getMemory_Address<string>(value_address);
        cout<<"Se creo un objeto long de nombre"<< this->name << "con un valor de" << this->longvar <<" almacenado en el offset numero " << value_address << endl;

    }

};


#endif //C_IDE_LONG_H
