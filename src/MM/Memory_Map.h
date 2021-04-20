//
// Created by mau14 on 19/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H
#define PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H
#include "string"
#include "iostream"
#include "../Data_Types/SimplyList.h"
#include "../Data_Types/Data_Type.h"
#include "Memory_Management.h"

using namespace std;

class Memory_Map {

private:
private:
    Memory_Map();
    static Memory_Map* unique_instance;

public:
    static Memory_Map *getInstance();
    //template<typename T>
    SimplyList<Data_Type> memory_map;

    //template<typename T>
    void append_list(Data_Type element){

        memory_map.append(element);

        if(memory_map.getLen() == 2){
            cout << memory_map.getHead()->getValue().getName() << " con un valor de  " << Memory_Management::getInstance()->searchmalloc<int>(memory_map.getHead()->getValue().getValueAddress()) <<endl;
            cout << memory_map.getHead()->getNext()->getValue().getName() << " con un valor de  " << Memory_Management::getInstance()->searchmalloc<float>(memory_map.getHead()->getNext()->getValue().getValueAddress()) <<endl;
        }

    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H
