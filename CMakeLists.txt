cmake_minimum_required(VERSION 3.17)
project(Proyecto_1_Datos_II_Server_C_)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Proyecto_1_Datos_II_Server_C_ main.cpp "src/Memory Management/Memory_Management.h" src/Data_Types/SimplyList.h src/Data_Types/Recycling_malloc.h src/Actions/Create_Type.cpp src/Actions/Create_Type.h src/Actions/Modify_Type.cpp src/Actions/Modify_Type.h src/Actions/Search_Type.cpp src/Actions/Search_Type.h src/MessageJson/JSON_Management.h src/MessageJson/Convert_request.cpp src/MessageJson/Convert_request.h src/Actions/Cast_to_Type.cpp src/Actions/Cast_to_Type.h src/Actions/Convert_Value.cpp src/Actions/Convert_Value.h src/MessageJson/TypeMessage.cpp src/MessageJson/TypeMessage.h "src/Memory Management/Memory_Management.cpp" "src/Memory Management/Memory_Map.cpp" "src/Memory Management/Memory_Map.h" src/Socket/Server.cpp src/Socket/Server.h src/MessageJson/RamLV.cpp src/MessageJson/RamLV.h src/MessageJson/Response.h)



