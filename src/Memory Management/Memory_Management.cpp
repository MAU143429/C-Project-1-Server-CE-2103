//
// Created by mau14 on 19/4/21.
//
#include "Memory_Management.h"
#include "iostream"
using namespace std;

Memory_Management* Memory_Management::unique_instance = NULL;
Memory_Management::Memory_Management(){}

 Memory_Management * Memory_Management::getInstance() {

    if(unique_instance == NULL){
        unique_instance = new Memory_Management();
    }
    return unique_instance;
}



