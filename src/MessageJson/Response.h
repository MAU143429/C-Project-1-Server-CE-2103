//
// Created by njohnson on 4/22/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__RESPONSE_H
#define PROYECTO_1_DATOS_II_SERVER_C__RESPONSE_H
#include <string>
using namespace std;
class Response {
public:
    string response;
    string code;
    string name;
    string value;
    string memory_address;
    string print;
    string type;
    int ref_count;

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        Response::type = type;
    }

    const string &getPrint() const {
        return print;
    }

    void setPrint(const string &print) {
        Response::print = print;
    }

    int getRefCount() const {
        return ref_count;
    }

    void setRefCount(int refCount) {
        ref_count = refCount;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Response::name = name;
    }

    const string &getValue() const {
        return value;
    }

    void setValue(const string &value) {
        Response::value = value;
    }

    const string &getMemoryAddress() const {
        return memory_address;
    }

    void setMemoryAddress(const string &memoryAddress) {
        memory_address = memoryAddress;
    }

    const string &getCode() const {
        return code;
    }

    void setCode(const string &code) {
        Response::code = code;
    }

    const string &getResponse() const {
        return response;
    }

    void setResponse(const string &response) {
        Response::response = response;
    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__RESPONSE_H
