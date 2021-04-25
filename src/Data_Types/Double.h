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
    /**
     * @brief Constructor for the Double class.
     * @param name
     * @param value
     */
    Double(string name, const char *value){
        this->name = name;
        this->doublevalue = Convert_Value::classify_type<double>("Double",value);
        this->ref_count = 0;
        this->size = 8;
        this->value_address = Memory_Management::getInstance()->appendElem(doublevalue);
        this->type="Double";
        cout<<"Se creo un objeto double de nombre"<< this->name << "con un valor de" << this->doublevalue << " almacenado en el offset numero " << value_address << endl;
    }

};


#endif //C_IDE_DOUBLE_H
