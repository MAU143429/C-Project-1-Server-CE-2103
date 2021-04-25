//
// Created by mau14 on 12/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__RECYCLING_MALLOC_H
#define PROYECTO_1_DATOS_II_SERVER_C__RECYCLING_MALLOC_H

#include "SimplyList.h"

template<typename T>
class Recycling_malloc{

private:
    SimplyList<T> Recycling;
public:
    /**
     * @brief Tells if the list is empty.
     * @return true if the list is empty false if not.
     */
    bool Empty(){
        return this->Recycling.getLen() == 0;
    }
    /**
     * @brief Adds an element to the recycling list.
     * @param element
     */
    void addAddress(T element){
        this->Recycling.append(element);
    }
    /**
     * @brief Getter for the head of the list.
     * @return the head of the recycling list.
     */
    T getFirst(){
        return this->Recycling.getHead()->getValue();
    }
    /**
     * @brief Deletes the head of the list.
     */
    void delFirst(){
        this->Recycling.delHead();
    }
};

#endif //PROYECTO_1_DATOS_II_SERVER_C__RECYCLING_MALLOC_H
