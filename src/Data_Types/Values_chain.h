//
// Created by mau14 on 12/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__VALUES_CHAIN_H
#define PROYECTO_1_DATOS_II_SERVER_C__VALUES_CHAIN_H

#include "SImplyList.h"

template<typename T>
class Values_chain{

private:
    SimplyList<T> list = new SimplyLIst();
public:

    bool Empty(){
        return this->list.getLen() == 0;
    }

    void queue(T element){
        this->list.append(element);
    }

    T show(){
        return this->list.getHead()->getValue();
    }

    void deQueue(){
        this->list.delHead();
    }
};

#endif //PROYECTO_1_DATOS_II_SERVER_C__VALUES_CHAIN_H
