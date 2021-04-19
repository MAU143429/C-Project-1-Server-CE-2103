#include <iostream>
#include "src/Data_Types/Data_Type.h"
#include "src/Convert_message/Convert_request.h"
#include "src/Convert_message/TypeMessage.h"
#include "src/TypeConversion/ObjectToJSON.h"
#include "src/TypeConversion/JSON_Management.h"
#include "src/Actions/Cast_to_Type.h"
#include "src/Actions/Convert_Value.h"


int main() {

    string change = "Long";
    const char *valor = "5874594895";
    cout << Convert_Value::classify_type<long>(change,valor);
    return 0;

}
