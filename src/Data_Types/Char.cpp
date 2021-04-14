//
// Created by njohnson on 3/30/21.
//

#include "Char.h"

string Char::getName() const {
    return Data_Type::getName();
}

void Char::setName(const string name) {
    Data_Type::setName(name);
}

int Char::getCount() const {
    return Data_Type::getCount();
}

void Char::setCount(int count) {
    Data_Type::setCount(count);
}

string Char::getValue() const {
    return Data_Type::getValue();
}

void Char::setValue(string value) {
    Data_Type::setValue(value);
}
