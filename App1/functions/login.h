//
// Created by Iulian on 5/29/2023.
//

#ifndef APP1_LOGIN_H
#define APP1_LOGIN_H

#include<iostream>
#include<string>
#include<fstream>

#include "helpers/fileExists.h"

void login(std::string name){
    std::replace( name.begin(), name.end(), '\'', '\0');
    std::ifstream fin("../../Share/Fisiere/Profesor_logat.txt");
    std::string fileName;
    std::getline(fin, fileName, '\n');

    if(fileName == ""){
        std::ofstream fout("../../Share/Fisiere/Profesor_logat.txt");
        if(fileExists(name)){
            fout<<name;
            std::cout<<"\nBuna ziua, "<<name<<" Puteti folosi urmatoarele comenzi: \n\n";
            std::cout<<" ./App1.exe vizualizare_profil \n";
            std::cout<<" ./App1.exe creare_test <id_test_de_creat> <nr_intrebari> \n";
            std::cout<<" ./App1.exe modificare_test <id_test> \n";
            std::cout<<" ./App1.exe delogare \n\n";
        }else{
            std::cout<<"Nu exista profesor cu numele "<<name<<". Rescrieti comanda de logare cu un nume existent.\n";
        }

        fout.close();


    }else{
        std::cout<<"\n "<<fileName<<" este logat! \n";
    }

    fin.close();
}

#endif //APP1_LOGIN_H
