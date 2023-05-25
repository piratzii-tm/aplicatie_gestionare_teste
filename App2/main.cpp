#include <iostream>
#include <cstring>
#include "../Share/Clase/Student.h"
#include "Functii/Logare.h"

using namespace std;

int main(int numberOfArguments, char **arguments) {
    if(numberOfArguments == 1) {
        cout << "Comenzi posibile: \n"
                "  logare <nume>\n"
                "  delogare";
        return 0;
    }

    if (strcmp(arguments[1], "logare") == 0){
        if(numberOfArguments != 3) {
            cout << "Sintaxa invalida! Sintaxa corecta: logare <nume>";
            return 0;
        }else{
            logare(arguments[2]);
            return 0;
        }
    }

    if (strcmp(arguments[1], "delogare") == 0){
        if(numberOfArguments != 2){
            cout << "Sintaxa invalida! Sintaxa corecta: delogare";
            return 0;
        }else {
            delogare();
            return 0;
        }
    }



    return 0;
}
