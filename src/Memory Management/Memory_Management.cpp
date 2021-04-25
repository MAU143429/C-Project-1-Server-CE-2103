//
// Created by mau14 on 19/4/21.
//
#include "Memory_Management.h"
#include "iostream"
using namespace std;

Memory_Management* Memory_Management::unique_instance{nullptr};
mutex Memory_Management::mutex_;

Memory_Management::Memory_Management(){}
Memory_Management::~Memory_Management() {}

 Memory_Management * Memory_Management::getInstance() {
    lock_guard<std::mutex> lock(mutex_);
    if(unique_instance == nullptr){unique_instance = new Memory_Management();}
    return unique_instance;
}



