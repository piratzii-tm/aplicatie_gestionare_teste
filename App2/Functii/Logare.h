#include <iostream>
#include <fstream>

#ifndef LOGARE_H
#define LOGARE_H

std::string LOGARE_FILE_NAME = "../../Share/Fisiere/Student_logat.txt";


void logare(const std::string& nume){

    std::ofstream fout(LOGARE_FILE_NAME);
    fout << nume;
    fout.close();

    std::cout << "Student logat: " << nume << '\n';
}

void delogare(){
    std::ofstream fout(LOGARE_FILE_NAME);
    fout << "";
    fout.close();

    std::cout << "Tocmai ai fost delogat\n";
}

#endif