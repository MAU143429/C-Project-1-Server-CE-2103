cmake_minimum_required(VERSION 3.17)
project(Proyecto_1_Datos_II_Server_C_)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto_1_Datos_II_Server_C_ main.cpp src/MM/Memory_Management.h src/Data_Types/SimplyList.h src/Data_Types/Values_chain.h src/Actions/Create_Type.cpp src/Actions/Create_Type.h src/Actions/Modify_Type.cpp src/Actions/Modify_Type.h src/Actions/Search_Type.cpp src/Actions/Search_Type.h)