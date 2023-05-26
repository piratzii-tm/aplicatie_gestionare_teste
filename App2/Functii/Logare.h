#include <iostream>
#include <fstream>

#ifndef LOGARE_H
#define LOGARE_H

string LOGARE_FILE_NAME = "../../Share/Fisiere/Student_logat.txt";


void logare(const std::string& nume){

    std::ofstream fin(LOGARE_FILE_NAME);
    fin << nume;
    fin.close();

    std::cout << "Student logat: " << nume << '\n';
}

void delogare(){
    std::ofstream fin(LOGARE_FILE_NAME);
    fin << "";
    fin.close();

    std::cout << "Tocmai ai fost delogat\n";
}

#endif