//
// Created by Poe on 02.06.2023.
//

#ifndef APP1_VERIFYLOGGEDPROF_H
#define APP1_VERIFYLOGGEDPROF_H

#include<iostream>
#include<fstream>
#include<string>

bool verifyLoggedProf(){
    std::ifstream fin("../../Share/Fisiere/Profesor_logat.txt");
    std::string numeProf;
    std::getline(fin,numeProf,'\n');
    if(numeProf == ""){return true;}
    return false;
}

#endif //APP1_VERIFYLOGGEDPROF_H
