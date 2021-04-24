//
// Created by mau14 on 19/4/21.
//

#include "Memory_Map.h"

using namespace std;

Memory_Map* Memory_Map::unique_instance{nullptr};
mutex Memory_Map::mutex_;

Memory_Map::Memory_Map(){}
Memory_Map::~Memory_Map() {}

Memory_Map * Memory_Map::getInstance() {
    lock_guard<std::mutex> lock(mutex_);
    if(unique_instance == nullptr){
        unique_instance = new Memory_Map();
    }
    return unique_instance;
}


