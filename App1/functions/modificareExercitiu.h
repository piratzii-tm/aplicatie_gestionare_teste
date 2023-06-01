//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_MODIFICAREEXERCITIU_H
#define APP1_MODIFICAREEXERCITIU_H
#include<iostream>
#include<fstream>
#include<string>

void modificareExercitiu(std::string numarExercitiu){
    std::ofstream fout("../files/modifyExercise.txt");
    fout<<numarExercitiu<<"\n";
    fout.close();

    std::cout<<"\nAi inceput sa modifici exercitiul "<<numarExercitiu<<". Acestea sunt comenzile posibile:\n\n";
    std::cout<<" ./App1.exe enunt '<noul_enunt>'\n";
    std::cout<<" ./App1.exe raspuns <litera_rapunsului> '<noul_rapuns>'\n";
    std::cout<<" ./App1.exe varianta_corecta <litera_rasp_corect>\n";
    std::cout<<" ./App1.exe stop_modificare_exercitiu\n";
    std::cout<<" ./App1.exe afiseaza_varianta_curenta\n\n";
}

#endif //APP1_MODIFICAREEXERCITIU_H
