//
// Created by mau14 on 12/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MANAGEMENT_H
#define PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MANAGEMENT_H


#include <mutex>
#include "iostream"
#include "../Data_Types/SimplyList.h"
#include "../Data_Types/Recycling_malloc.h"
#include "../Data_Types/Data_Type.h"
#include "sstream"
#include "string"


using namespace std;


class Memory_Management{
protected:
    Memory_Management();
    ~Memory_Management();
private:
    static Memory_Management* unique_instance;
    static mutex mutex_;
public:
    void *ptr;
    int offset;
    static Memory_Management *getInstance();
    Recycling_malloc<int> Recycling_addr;
    /**
     * @brief Method that doesn't let the Memory_Management instance be assignable.
     * @param other
     */
    Memory_Management(Memory_Management &other) = delete;
    /**
     * Method that doesn't let the Memory_Management instance be cloneable.
     */
    void operator=(const Memory_Management &) = delete;

    /**
     * @brieg Initializes the malloc
     * @param size the size for the memory block that gets created.
     */
    void InitMalloc(size_t size){
        ptr = malloc(size);
        offset = 1;
    }
    /**
     * @brief Appends the element to the malloc created.
     * @tparam T
     * @param element
     * @return the memory address of the temp variable plus the offset.
     */
    template<typename T>
    int appendElem(T element){
        int addr;
        int newaddr;
        if(Recycling_addr.Empty()){
            T *temp = (T *)ptr;
            *(temp+offset) = element;
            addr = offset;
            offset++;

            return addr;
        }else{
            int newaddr = Recycling_addr.getFirst();
            T *temp = (T *)ptr;
            *(temp+newaddr) = element;
            addr = newaddr;
            Recycling_addr.delFirst();
            cout<< "VALOR DEL MALLOC EN LA POS 1 = " << searchmalloc<int>(newaddr) << endl;
            return addr;
        }
    }
    /**
     *
     * @tparam T
     * @param offset
     * @return
     */
    template<typename T>
    T searchmalloc(int offset){
        T *temp = (T *)ptr;
        return *(temp+offset);
    }
    /**
     * @brief Modifies a value contained in the malloc using the offset to access it.
     * @tparam T
     * @param value
     * @param offset
     */
    template<typename T>
    string Get_mallocvalue(int offset){
        T *temp = (T *)ptr;
        std::ostringstream newvalue;
        newvalue << (*(temp+offset));
        const char *value = newvalue.str().c_str();
        return value;
    }

    template<typename T>
    void modifymalloc(T value,int offset){
        T *temp = (T *)ptr;
        *(temp+offset) = value;
    }
    /**
     * @brief Getter for the memory address using the offset
     * @tparam T
     * @param offset
     * @return the memory address
     */
    template<typename T>
    string getMemory_Address(int offset){
        T *temp = (T *)ptr;
        std::ostringstream newaddress;
        newaddress << ((temp+offset));
        const char *address = newaddress.str().c_str();
        return address;
    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MANAGEMENT_H
