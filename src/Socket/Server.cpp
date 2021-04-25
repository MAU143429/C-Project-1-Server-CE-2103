//
// Created by mau14 on 19/4/21.
//

#include "Server.h"
Server* Server::unique_instance{nullptr};
mutex Server::mutex_;

Server::Server() {}
Server::~Server() {}

Server *Server::getInstance() {
    lock_guard<std::mutex> lock(mutex_);
    if (unique_instance == nullptr){unique_instance = new Server();}
    return unique_instance;
}
