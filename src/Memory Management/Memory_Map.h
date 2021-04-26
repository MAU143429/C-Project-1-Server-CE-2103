//
// Created by mau14 on 19/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H
#define PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H
#include "string"
#include <mutex>
#include "iostream"
#include "../Data_Types/SimplyList.h"
#include "../Data_Types/Data_Type.h"
#include "Memory_Management.h"

using namespace std;

class Memory_Map {
protected:
    Memory_Map();
    ~Memory_Map();
private:
    static Memory_Map* unique_instance;
    static mutex mutex_;

public:
    SimplyList<Data_Type> memory_map;
    static Memory_Map *getInstance();
    /**
     * @brief Method that doesn't let the Memory_Map be assignable.
     * @param other
     */
    Memory_Map(Memory_Map &other) = delete;
    /**
     * @brief Method that doesn't let the Memory_Map instance be cloneable.
     */
    void operator=(const Memory_Map &) = delete;
    /**
     * @brief Appends the Data_Type element to the memory map.
     * @param element the Data_Type object.
     */
    //template<typename T>
    void append_list(Data_Type element){

        memory_map.append(element);
        Memory_Map::getInstance()->PrintMemoryMap(memory_map);

    }
    /**
     * @brief Prints the memory map with the different variables contained in the memory map.
     * @param simplyList
     */
    void PrintMemoryMap(SimplyList<Data_Type> simplyList){

        cout << " ################################  SERVER MEMORY MAP    ################################ \n";
        for (int i = 0; i < simplyList.getLen(); ++i) {

            string name = simplyList.getNode(i)->getValue().getName();
            string type = simplyList.getNode(i)->getValue().getType();
            int count = simplyList.getNode(i)->getValue().getRefCount();
            int size = simplyList.getNode(i)->getValue().getSize();
            int position = simplyList.getNode(i)->getValue().getValueAddress();

            cout<< "                                                                                         \n" <<
                "                             Valor en pos "<< position << "                                 \n" <<
                "                        NOMBRE DE LA VARIABLE :  " << name << "                             \n" <<
                "                        TIPO DE DATO :           " << type << "                             \n" <<
                "                        CUENTA CON:              "<< count <<" REFERENCIAS                 \n" ;
            if(type == "Integer"){
                int valueofint = Memory_Management::getInstance()->searchmalloc<int>(memory_map.getNode(i)->getValue().getValueAddress());
                cout << "                        VALUE OF:                " << valueofint << endl;
            }else if(type == "Long"){
                long valueoflong = Memory_Management::getInstance()->searchmalloc<long>(memory_map.getNode(i)->getValue().getValueAddress());
                cout << "                        VALUE OF:                " << valueoflong << endl;
            }else if(type == "Float"){
                float valueoffloat = Memory_Management::getInstance()->searchmalloc<float>(memory_map.getNode(i)->getValue().getValueAddress());
                cout << "                        VALUE OF:                " << valueoffloat << endl;
            }else if(type == "Double"){
                double valueofdouble = Memory_Management::getInstance()->searchmalloc<double>(memory_map.getNode(i)->getValue().getValueAddress());
                cout << "                        VALUE OF:                " << valueofdouble << endl;
            }else if(type == "Char"){
                char valueofchar = Memory_Management::getInstance()->searchmalloc<char>(memory_map.getNode(i)->getValue().getValueAddress());
                cout << "                        VALUE OF:                " << valueofchar << endl;
            }





        }
        cout << " ################################          END          ################################    \n" << endl;
    }
    /**
     * @brief Boolean method that searches for an element in the memory map using the name and the type
     * @param name the name of the variable that gets searched
     * @param type the type of the variable that gets searched
     * @return true if the variables is in the memory map and false if its not.
     */
    bool BoolSearch(string name, string type){

        for (int i = 0; i < memory_map.getLen(); ++i) {

            if(memory_map.getNode(i)->getValue().getName() == name and memory_map.getNode(i)->getValue().getType() == type){
                return true;
            }
        }
        return false;

    }
    /**
     * @brief Boolean method that searches for the name of the variable
     * @param name the name that gets searched
     * @return true if the name is contained in the memory map and false if its not.
     */
    bool Search_Name(string name){
        cout<<memory_map.getLen()<<endl;
        if(memory_map.getLen() == 0){
            return false;
        }
        for (int i = 0; i < memory_map.getLen(); ++i) {

            if(memory_map.getNode(i)->getValue().getName() == name){
                return true;
            }
        }
        return false;

    }
    /**
    * @brief Gets the name of the variable searched in the memory map.
    * @param name the name that gets searched.
    * @return string of the name of the variable.
    */
    string Get_Name(string name){

        for (int i = 0; i < memory_map.getLen(); ++i) {
            if(memory_map.getNode(i)->getValue().getName() == name){
                return memory_map.getNode(i)->getValue().getName();
            }
        }
    }
    /**
     * @brief Gets the type of the variable using the name of the variable contained in the memory map.
     * @param name
     * @return
     */
    string Get_Type(string name){

        for (int i = 0; i < memory_map.getLen(); ++i) {
            if(memory_map.getNode(i)->getValue().getName() == name){
                return memory_map.getNode(i)->getValue().getType();
            }
        }
    }
    /**
     *
     * @param name
     * @return
     */
    string Get_MemoryAddress(string name){

        for (int i = 0; i < memory_map.getLen(); ++i) {
            if(memory_map.getNode(i)->getValue().getName() == name){
                return memory_map.getNode(i)->getValue().getMemoryAdrr();
            }
        }
    }
    /**
     *
     * @param name
     * @return
     */
    int Get_RefCount(string name){

        for (int i = 0; i < memory_map.getLen(); ++i) {
            if(memory_map.getNode(i)->getValue().getName() == name){
                return memory_map.getNode(i)->getValue().getRefCount();
            }
        }
    }
    /**
     *
     * @param name
     * @return
     */
    int Get_Offset(string name){

        for (int i = 0; i < memory_map.getLen(); ++i) {
            if(memory_map.getNode(i)->getValue().getName() == name){
                return memory_map.getNode(i)->getValue().getValueAddress();
            }
        }
    }

    /**
     * @brief Method that searches the memory map for an existing variable
     * @tparam T
     * @param name
     * @param type
     * @param modvalue
     */
    template<typename T>
    void Modify_Value(string name, string type, T modvalue){
        int address;
        for (int i = 0; i < memory_map.getLen(); ++i) {

            if(memory_map.getNode(i)->getValue().getName() == name and memory_map.getNode(i)->getValue().getType() == type){
                address = memory_map.getNode(i)->getValue().getValueAddress();
                Memory_Management::getInstance()->template modifymalloc(modvalue,address);
                PrintMemoryMap(memory_map);
                cout<< "VALOR MODIFICADO CON EXITO"<<endl;
            } else{
                if(memory_map.getNode(i)->getValue().getName() != name){
                    cout<<"EL NOMBRE DE LA VARIABLE QUE SE DESEA MODIFICAR NO EXISTE."<<endl;
                }else if(memory_map.getNode(i)->getValue().getType() != type){
                    cout<<"EL TIPO DE VARIBLE NO COINCIDE CON NINGUNA"<<endl;
                }
            }

        }


    }
};
#endif //PROYECTO_1_DATOS_II_SERVER_C__MEMORY_MAP_H

