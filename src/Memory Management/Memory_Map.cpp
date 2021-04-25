//
// Created by mau14 on 19/4/21.
//

#include "Memory_Map.h"

using namespace std;

Memory_Map* Memory_Map::unique_instance{nullptr};
mutex Memory_Map::mutex_;
/**
 * @brief constructor for Memory_Map class.
 */
Memory_Map::Memory_Map(){}
/**
 * @brief destructor for Memory_Map class.
 */
Memory_Map::~Memory_Map() {}
/**
 * @brief Singleton getter for the Memory_Map unique instance.
 * @return the unique Memory_Map instance.
 */
Memory_Map * Memory_Map::getInstance() {
    lock_guard<std::mutex> lock(mutex_);
    if(unique_instance == nullptr){
        unique_instance = new Memory_Map();
    }
    return unique_instance;
}


