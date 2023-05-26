#include <iostream>
#include <fstream>
#include <string>
#include "../Variabile.h"

#ifndef APP2_RASPUNS_INTREBARE_H
#define APP2_RASPUNS_INTREBARE_H


void raspuns_intrebare(const std::string raspuns){
    //verificam daca raspunsul este unul corect
    if(raspuns != "a" && raspuns != "b" && raspuns != "c" && raspuns != "d"){
        std::cout << "RASPUNS POSIBIL: a, b, c, d\n";
        return;
    }

    std::string nume_test;

    std::ifstream fin_test_curent(FILE_TEST_CURENT);
    if(getline(fin_test_curent, nume_test)){
        std::cout << "URMATOAREA INTREBARE\n";

    }else{
        std::cout << "NU ESTE PORNIT NICI UN TEST\n";
        fin_test_curent.close();
        return;
    }
    fin_test_curent.close();

}

#endif //APP2_RASPUNS_INTREBARE_H
