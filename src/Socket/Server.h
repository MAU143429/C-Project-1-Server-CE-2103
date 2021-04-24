//
// Created by mau14 on 19/4/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__SERVER_H
#define PROYECTO_1_DATOS_II_SERVER_C__SERVER_H
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <thread>
#include "../MessageJson/JSON_Management.h"
#include "../MessageJson/Convert_request.h"

using namespace std;

class Server {

protected:
    Server();
    ~Server() {}
private:
    static Server* unique_instance;
    static mutex mutex_;
public:
    int clientSocket;
    string client_message;
    static Server* getInstance();
    void operator=(const Server &) = delete;
    Server(Server &other) = delete;



    int InitServer(){
        // Create a socket
        int listening = socket(AF_INET, SOCK_STREAM, 0);
        if (listening == -1)
        {
            cerr << "Can't create a socket! Quitting" << endl;
            return -1;
        }

        // Bind the ip address and port to a socket
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(54000);
        inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

        bind(listening, (sockaddr*)&hint, sizeof(hint));

        // Tell Winsock the socket is for listening
        listen(listening, SOMAXCONN);

        // Wait for a connection
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

        char host[NI_MAXHOST];      // Client's remote name
        char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

        memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
        {
            cout << host << " connected on port " << service << endl;
        }
        else
        {
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            cout << host << " connected on port " << ntohs(client.sin_port) << endl;
        }

        // Close listening socket
        close(listening);

        // While loop: accept and echo message back to client
        char buf[4096];
        string userInput;
        while (true)
        {

            memset(buf, 0, 4096);

            // Wait for client to send data
            int bytesReceived = recv(clientSocket, buf, 4096, 0);
            if (bytesReceived == -1)
            {
                cerr << "Error in recv(). Quitting" << endl;
                break;
            }

            if (bytesReceived == 0)
            {
                cout << "Client disconnected " << endl;
                break;
            }


            client_message = string(buf, 0, bytesReceived);
            if(!client_message.empty()){
                const string &response = Convert_request::Select_Type_Message(client_message);
                Send(response.c_str());

            }
        }

        // Close the socket
        close(clientSocket);

        return 0;
    }

    void Send(const char *msg) {
        int sendRes = send(clientSocket, msg, strlen(msg), 0);
        if (sendRes == -1) {
            std::cout << "Send message failed" << std::endl;
        }
    }


    string ReadString(){
        return client_message;
    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__SERVER_H
