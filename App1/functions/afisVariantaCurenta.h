//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_AFISVARIANTACURENTA_H
#define APP1_AFISVARIANTACURENTA_H

#include<iostream>
#include<fstream>
#include<string>
#include "../classes/Test.h"

void afisVariantaCurenta(){
    std::ifstream fin("../files/modifyTest.txt");
    std::string testId;
    std::getline(fin,testId,'\n');
    fin.close();

    std::string pathToTest = "../../Share/Fisiere/Teste/"+testId+".txt";
    std::fstream gin(pathToTest);
    Test test;
    gin>>test;
    test.afisareProfil(0);
    gin.close();

}

#endif //APP1_AFISVARIANTACURENTA_H
