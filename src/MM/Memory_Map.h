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
        Memory_Map::getInstance()->show_memorymap(memory_map);


    }

    void show_memorymap(SimplyList<Data_Type> list_show){
        string type,name,size;
        char valueofchar;
        int valueofint,position,count;
        float valueoffloat;
        double valueofdouble;
        long valueoflong;

        if(list_show.getHead()->getNext()  != nullptr){

            name = list_show.getHead()->getValue().getName();
            type = list_show.getHead()->getValue().getType();
            count = list_show.getHead()->getValue().getRefCount();
            size = list_show.getHead()->getValue().getSize();
            position = list_show.getHead()->getValue().getValueAddress();

            if(type == "Integer"){
                valueofint = Memory_Management::getInstance()->searchmalloc<int>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Long"){
                valueoflong = Memory_Management::getInstance()->searchmalloc<long>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Float"){
                valueoffloat = Memory_Management::getInstance()->searchmalloc<float>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Double"){
                valueofdouble = Memory_Management::getInstance()->searchmalloc<double>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Char"){
                valueofchar = Memory_Management::getInstance()->searchmalloc<char>(memory_map.getHead()->getValue().getValueAddress());
            }
            cout<< " ################################  SERVER MEMORY MAP    ################################ \n" <<
                "                             Valor en pos "<< position << "                                 \n" <<
                "                        NOMBRE DE LA VARIABLE :  " << name << "                             \n" <<
                "                        TIPO DE DATO :           " << type << "                             \n" <<
                "                        CON UN VALOR DE :        "<< valueofint <<"                         \n" <<
                "                        CUENTA CON:               "<< count <<" REFERENCIAS                 \n" <<
                " ################################          END          ################################    \n" <<endl;

            list_show.setHead(list_show.getHead()->getNext());
        }else{
            name = list_show.getHead()->getValue().getName();
            type = list_show.getHead()->getValue().getType();
            count = list_show.getHead()->getValue().getRefCount();
            size = list_show.getHead()->getValue().getSize();
            position = list_show.getHead()->getValue().getValueAddress();

            if(type == "Integer"){
                valueofint = Memory_Management::getInstance()->searchmalloc<int>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Long"){
                valueoflong = Memory_Management::getInstance()->searchmalloc<long>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Float"){
                valueoffloat = Memory_Management::getInstance()->searchmalloc<float>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Double"){
                valueofdouble = Memory_Management::getInstance()->searchmalloc<double>(memory_map.getHead()->getValue().getValueAddress());
            }else if(type == "Char"){
                valueofchar = Memory_Management::getInstance()->searchmalloc<char>(memory_map.getHead()->getValue().getValueAddress());
            }
            cout<< " ################################  SERVER MEMORY MAP    ################################ \n" <<
                "                             Valor en pos "<< position << "                                 \n" <<
                "                        NOMBRE DE LA VARIABLE :  " << name << "                             \n" <<
                "                        TIPO DE DATO :           " << type << "                             \n" <<
                "                        CON UN VALOR DE :        "<< valueofint <<"                         \n" <<
                "                        CUENTA CON:               "<< count <<" REFERENCIAS                 \n" <<
                " ################################          END          ################################    \n" <<endl;

        }
/**
        for (int i = 0; i < list_show.getLen(); ++i) {

            name = list_show.getNode(i).getValue().getName();
            type = list_show.getNode(i).getValue().getType();
            count = list_show.getNode(i).getValue().getRefCount();
            size = list_show.getNode(i).getValue().getSize();
            position = list_show.getNode(i).getValue().getValueAddress();

            if(type == "Integer"){
                valueofint = Memory_Management::getInstance()->searchmalloc<int>(memory_map.getNode(i).getValue().getValueAddress());
            }else if(type == "Long"){
                valueoflong = Memory_Management::getInstance()->searchmalloc<long>(memory_map.getNode(i).getValue().getValueAddress());
            }else if(type == "Float"){
                valueoffloat = Memory_Management::getInstance()->searchmalloc<float>(memory_map.getNode(i).getValue().getValueAddress());
            }else if(type == "Double"){
                valueofdouble = Memory_Management::getInstance()->searchmalloc<double>(memory_map.getNode(i).getValue().getValueAddress());
            }else if(type == "Char"){
                valueofchar = Memory_Management::getInstance()->searchmalloc<char>(memory_map.getNode(i).getValue().getValueAddress());
            }

            cout<< " ################################  SERVER MEMORY MAP    ################################ \n" <<
                   "                                                                                         \n"
                   "                        NOMBRE DE LA VARIABLE =  "<< endl;

        }*/

    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H
