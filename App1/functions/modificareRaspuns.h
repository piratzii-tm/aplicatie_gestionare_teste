//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_MODIFICARERASPUNS_H
#define APP1_MODIFICARERASPUNS_H

#include<iostream>
#include<fstream>
#include<string>
#include "../classes/Test.h"

void modificareRaspuns(std::string lit, std::string nouRaspuns){
    std::ifstream fin("../files/modifyTest.txt");
    std::string testId;
    std::getline(fin,testId,'\n');
    fin.close();

    std::string pathToTest = "../../Share/Fisiere/Teste/"+testId+".txt";
    std::fstream gin(pathToTest);
    Test test;
    gin>>test;
    gin.close();

    std::fstream hin("../files/modifyExercise.txt");
    int exNr;
    hin>>exNr;
    hin.close();

    int nrRasp;
    if(lit == "a"){nrRasp =0;}else
    if(lit == "b"){nrRasp =1;}else
    if(lit == "c"){nrRasp =2;}else
    if(lit == "d"){nrRasp =3;}else{
        std::cout<<"\n Nu exista rapuns cu aceasta litera!\n";
        return;
    }

    test.setRaspuns(exNr,nrRasp,nouRaspuns);

    std::fstream gout(pathToTest);
    gout<<test;
    gout.close();

    std::fstream nout(pathToTest, std::ios::app);
    for(int i =0;i<10;i++){
        nout<<test.getStats()[i]<<" ";
    }
    nout.close();

    std::cout<<"\nRaspunsul "<<lit<<" pentru exercitiul "<< exNr<<" a fost modificat cu succes!\n";
}


#endif //APP1_MODIFICARERASPUNS_H
