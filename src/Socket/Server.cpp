//
// Created by mau14 on 19/4/21.
//

#include "Server.h"
Server* Server::unique_instance = NULL;
Server::Server() {}

Server *Server::getInstance() {
    if (unique_instance == NULL){unique_instance = new Server();}
    return unique_instance;
}
