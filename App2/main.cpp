#include <iostream>
#include <cstring>
#include "../Share/Clase/Student.h"
#include "Functii/Logare.h"
#include "Functii/Deschide_test.h"
#include "Functii/Raspuns_intrebare.h"


int main(int numberOfArguments, char **arguments) {

    if(numberOfArguments == 1) {
        std::cout << "Comenzi posibile: \n"
                "  logare <nume>\n"
                "  deschide_test <idTest>\n"
                "  raspuns_intrebare <raspuns>\n"
                "  delogare";
        return 0;
    }

    if (strcmp(arguments[1], "logare") == 0){
        if(numberOfArguments != 3) {
            std::cout << "Sintaxa invalida! Sintaxa corecta: logare <nume>";
            return 0;
        }else{
            logare(arguments[2]);
            return 0;
        }
    }

    if(strcmp(arguments[1], "deschide_test") == 0){
        if(numberOfArguments != 3) {
            std::cout << "Sintaxa invalida! Sintaxa corenta: deschide_test <idTest>";
            return 0;
        }else {
            deschide_test(arguments[2]);
            return 0;
        }
    }

    if(strcmp(arguments[1], "raspuns_intrebare") == 0){
        if(numberOfArguments != 3){
            std::cout << "Sintaxa invalida! Sintaxa corenta: raspuns_intrebare <raspuns>";
            return 0;
        }else {
            raspuns_intrebare(arguments[2]);
            return 0;
        }
    }


    if (strcmp(arguments[1], "delogare") == 0){
        if(numberOfArguments != 2){
            std::cout << "Sintaxa invalida! Sintaxa corecta: delogare";
            return 0;
        }else {
            delogare();
            return 0;
        }
    }

    std::cout << "Comanda invalida!";
    return 0;
}
