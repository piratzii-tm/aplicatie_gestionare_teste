#include <iostream>
#include <fstream>

using namespace std;

#ifndef LOGARE_H
#define LOGARE_H

string LOGARE_FILE_NAME = "../../Share/Fisiere/Student_logat.txt";


void logare(const string& nume){

    ofstream fin(LOGARE_FILE_NAME);
    fin << nume;
    fin.close();

    cout << "Student logat: " << nume << '\n';
}

void delogare(){
    ofstream fin(LOGARE_FILE_NAME);
    fin << "";
    fin.close();

    cout << "Tocmai ai fost delogat\n";
}

#endif