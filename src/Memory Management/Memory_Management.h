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

    Memory_Management(Memory_Management &other) = delete;
    void operator=(const Memory_Management &) = delete;

    void InitMalloc(size_t size){
        ptr = malloc(size);
        offset = 1;
    }

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
            return addr;
        }
    }

    template<typename T>
    T searchmalloc(int offset){
        T *temp = (T *)ptr;
        return *(temp+offset);
    }

    template<typename T>
    void modifymalloc(T value,int offset){
        T *temp = (T *)ptr;
        *(temp+offset) = value;
    }
};


#endif //PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MANAGEMENT_H
