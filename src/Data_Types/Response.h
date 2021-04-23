//
// Created by njohnson on 4/22/21.
//

#ifndef PROYECTO_1_DATOS_II_SERVER_C__RESPONSE_H
#define PROYECTO_1_DATOS_II_SERVER_C__RESPONSE_H
#include <string>
using namespace std;
class Response {
public:
    string response;

    const string &getResponse() const {
        return response;
    }

    void setResponse(const string &response) {
        Response::response = response;
    }

};


#endif //PROYECTO_1_DATOS_II_SERVER_C__RESPONSE_H
