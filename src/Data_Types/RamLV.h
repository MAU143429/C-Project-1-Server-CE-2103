//
// Created by njohnson on 4/22/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__RAMLV_H
#define PROYECTO_1_DATOS_II_SERVER_C__RAMLV_H
#include <string>

using namespace std;

class RamLV {
public:
    string memoryAddr, value, name, refCounter;

    const string &getMemoryAddr() const;

    void setMemoryAddr(const string &memoryAddr);

    const string &getValue() const;

    void setValue(const string &value);

    const string &getName() const;

    void setName(const string &name);

    const string &getRefCounter() const;

    void setRefCounter(const string &refCounter);

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__RAMLV_H
