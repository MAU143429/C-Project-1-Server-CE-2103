//
// Created by mau14 on 19/4/21.
//

#include "Memory_Map.h"
#include "iostream"
using namespace std;

Memory_Map* Memory_Map::unique_instance = NULL;
Memory_Map::Memory_Map(){}

Memory_Map * Memory_Map::getInstance() {

    if(unique_instance == NULL){
        unique_instance = new Memory_Map();
    }
    return unique_instance;
}