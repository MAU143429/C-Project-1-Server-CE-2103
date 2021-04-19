//
// Created by njohnson on 3/31/21.
//

#ifndef C_IDE_DATATYPE_H
#define C_IDE_DATATYPE_H
#include <string>
using namespace std;
class Data_Type{


public:
    string name;
    string type;

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        Data_Type::type = type;
    }

    const char *value;
    int size;
    int ref_count;
    int *value_address;



    int getSize() const {
        return size;
    }

    void setSize(int size) {
        Data_Type::size = size;
    }

    int getRefCount() const {
        return ref_count;
    }

    void setRefCount(int refCount) {
        ref_count = refCount;
    }

    int *getValueAddress() const {
        return value_address;
    }

    void setValueAddress(int *valueAddress) {
        value_address = valueAddress;
    }

    /**
     * @brief Getter for name
     * @return name in string
     */
    virtual string getName() const {
        return name;
    }

    /**
     * @brief Setter for name
     * @param the name of the variable
     */
    virtual void setName(string name) {
        Data_Type::name = name;
    }

    const char *getValue() const {
        return value;
    }

    void setValue(const char *value) {
        Data_Type::value = value;
    }
};

#endif //C_IDE_DATATYPE_H
