#include <iostream>
#include <fstream>
#include "../Variabile.h"


#ifndef LOGARE_H
#define LOGARE_H



void delogare();

void logare(const std::string& nume){

    //Mai intai verificam daca este logat cineva defa
    std::ifstream fin_nume(LOGARE_FILE_NAME);
    std::string aux_nume;

    if(getline(fin_nume, aux_nume)){
        delogare();
        logare(nume);
        fin_nume.close();
        return;
    }else{
        std::ofstream fout(LOGARE_FILE_NAME);
        fout << nume;
        fout.close();
    }

    std::cout << "Student logat: " << nume << '\n';
}

void delogare(){
    //stergere din fisierul Student_logat.txt
    std::ofstream fout(LOGARE_FILE_NAME);
    fout << "";
    fout.close();

    //stergere din fisier Test_Curent.txt
    std::ofstream fout_test_curent(FILE_TEST_CURENT);
    fout_test_curent << "";
    fout_test_curent.close();

    //stergere din fisier respunsuri test curent
    std::ofstream fout_raspunsuri_test_curent(FILE_RASPUNSURI_TEST_CURENT);
    fout_raspunsuri_test_curent << "";
    fout_raspunsuri_test_curent.close();

    std::cout << "Tocmai ai fost delogat\n";
}

#endif