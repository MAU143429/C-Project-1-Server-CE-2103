//
// Created by njohnson on 3/30/21.
//

#include "Long.h"

string Long::getName() const {
    return Data_Type::getName();
}

void Long::setName(string name) {
    Data_Type::setName(name);
}

int Long::getCount() const {
    return Data_Type::getCount();
}

void Long::setCount(int count) {
    Data_Type::setCount(count);
}

string Long::getValue() const {
    return Data_Type::getValue();
}

void Long::setValue(string value) {
    Data_Type::setValue(value);
}
