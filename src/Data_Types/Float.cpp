//
// Created by njohnson on 3/30/21.
//

#include "Float.h"

string Float::getName() const {
    return Data_Type::getName();
}

void Float::setName(string name) {
    Data_Type::setName(name);
}

int Float::getCount() const {
    return Data_Type::getCount();
}

void Float::setCount(int count) {
    Data_Type::setCount(count);
}

string Float::getValue() const {
    return Data_Type::getValue();
}

void Float::setValue(string value) {
    Data_Type::setValue(value);
}
