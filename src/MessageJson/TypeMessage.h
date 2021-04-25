//
// Created by mau14 on 19/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__TYPEMESSAGE_H
#define PROYECTO_1_DATOS_II_SERVER_C__TYPEMESSAGE_H
#include "string"
using namespace std;

class TypeMessage {

public:
    string type, name, modifyvalue, action, value, size, response, code,memory_address,ref_count;

    const string &getMemoryAddress() const;

    void setMemoryAddress(const string &memoryAddress);

    const string &getRefCount() const;

    void setRefCount(const string &refCount);

    const string &getResponse() const;

    void setResponse(const string &response);

    const string &getType() const;

    void setType(const string &type);

    const string &getName() const;

    void setName(const string &name);

    const string &getModifyvalue() const;

    void setModifyvalue(const string &modifyvalue);

    const string &getAction() const;

    void setAction(const string &action);

    const string &getValue() const;

    void setValue(const string &value);

    const string &getSize() const;

    void setSize(const string &size);

    const string &getCode() const;

    void setCode(const string &code);

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__TYPEMESSAGE_H
