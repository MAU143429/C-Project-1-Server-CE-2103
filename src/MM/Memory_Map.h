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
        Memory_Map::getInstance()->PrintMemoryMap(memory_map);

    }

    void PrintMemoryMap(SimplyList<Data_Type> simplyList){

        cout << " ################################  SERVER MEMORY MAP    ################################ \n" << endl;
        for (int i = 0; i < simplyList.getLen(); ++i) {

            string name = simplyList.getNode(i)->getValue().getName();
            string type = simplyList.getNode(i)->getValue().getType();
            int count = simplyList.getNode(i)->getValue().getRefCount();
            int size = simplyList.getNode(i)->getValue().getSize();
            int position = simplyList.getNode(i)->getValue().getValueAddress();

            if(type == "Integer"){
                int valueofint = Memory_Management::getInstance()->searchmalloc<int>(memory_map.getNode(i)->getValue().getValueAddress());
            }else if(type == "Long"){
                long valueoflong = Memory_Management::getInstance()->searchmalloc<long>(memory_map.getNode(i)->getValue().getValueAddress());
            }else if(type == "Float"){
                float valueoffloat = Memory_Management::getInstance()->searchmalloc<float>(memory_map.getNode(i)->getValue().getValueAddress());
            }else if(type == "Double"){
                double valueofdouble = Memory_Management::getInstance()->searchmalloc<double>(memory_map.getNode(i)->getValue().getValueAddress());
            }else if(type == "Char"){
                char valueofchar = Memory_Management::getInstance()->searchmalloc<char>(memory_map.getNode(i)->getValue().getValueAddress());
            }


            cout<< "                             Valor en pos "<< position << "                                 \n" <<
                   "                        NOMBRE DE LA VARIABLE :  " << name << "                             \n" <<
                   "                        TIPO DE DATO :           " << type << "                             \n" <<
                   "                        CON UN VALOR DE :        "<< 2 <<"                         \n" <<
                   "                        CUENTA CON:               "<< count <<" REFERENCIAS                 \n" <<endl;


        }
        cout << " ################################          END          ################################    \n" << endl;
    }

     bool BoolSearch(string name, string type){

        for (int i = 0; i < memory_map.getLen(); ++i) {

            if(memory_map.getNode(i)->getValue().getName() == name and memory_map.getNode(i)->getValue().getType() == type){
                return true;
            }
        }
         return false;

    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H
