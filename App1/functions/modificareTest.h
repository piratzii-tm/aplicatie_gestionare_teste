//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_MODIFICARETEST_H
#define APP1_MODIFICARETEST_H

#include<iostream>
#include<string>
#include<fstream>

void modificareTest(std::string idTest){
    std::ofstream fout("../files/modifyTest.txt");
    fout<<idTest<<"\n";
    fout.close();

    std::cout<<"\n Ai pornit o sesiunde de modificare test! Comenzile posibile sunt:\n\n";
    std::cout<<" ./App1.exe modificare_exercitiu <nr_exercitiu>\n";
    std::cout<<" ./App1.exe stop_modificare_test\n";
    std::cout<<" ./App1.exe afiseaza_varianta_curenta\n\n";

}

#endif //APP1_MODIFICARETEST_H
