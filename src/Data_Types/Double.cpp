//
// Created by njohnson on 3/30/21.
//

#include "Double.h"

string Double::getName() const {
    return Data_Type::getName();
}

void Double::setName(string name) {
    Data_Type::setName(name);
}

int Double::getCount() const {
    return Data_Type::getCount();
}

void Double::setCount(int count) {
    Data_Type::setCount(count);
}

string Double::getValue() const {
    return Data_Type::getValue();
}

void Double::setValue(string value) {
    Data_Type::setValue(value);
}
