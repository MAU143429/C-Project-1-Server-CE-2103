cmake_minimum_required(VERSION 3.17)
project(Proyecto_1_Datos_II_Server_C_)

set(CMAKE_CXX_STANDARD 14)


add_executable(Proyecto_1_Datos_II_Server_C_ main.cpp src/MM/Memory_Management.h src/Data_Types/SimplyList.h src/Data_Types/Recycling_malloc.h src/Actions/Create_Type.cpp src/Actions/Create_Type.h src/Actions/Modify_Type.cpp src/Actions/Modify_Type.h src/Actions/Search_Type.cpp src/Actions/Search_Type.h src/TypeConversion/JSON_Management.h src/Convert_message/Convert_request.cpp src/Convert_message/Convert_request.h src/Actions/Cast_to_Type.cpp src/Actions/Cast_to_Type.h src/Actions/Convert_Value.cpp src/Actions/Convert_Value.h src/Convert_message/TypeMessage.cpp src/Convert_message/TypeMessage.h src/MM/Memory_Management.cpp src/MM/Memory_Map.cpp src/MM/Memory_Map.h)



