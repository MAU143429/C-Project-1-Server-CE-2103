//
// Created by njohnson on 4/22/21.
//

#include "RamLV.h"

const string &RamLV::getMemoryAddr() const {
    return memoryAddr;
}

void RamLV::setMemoryAddr(const string &memoryAddr) {
    RamLV::memoryAddr = memoryAddr;
}

const string &RamLV::getValue() const {
    return value;
}

void RamLV::setValue(const string &value) {
    RamLV::value = value;
}

const string &RamLV::getName() const {
    return name;
}

void RamLV::setName(const string &name) {
    RamLV::name = name;
}

const string &RamLV::getRefCounter() const {
    return refCounter;
}

void RamLV::setRefCounter(const string &refCounter) {
    RamLV::refCounter = refCounter;
}
