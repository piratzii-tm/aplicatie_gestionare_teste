//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_MODIFICARERASPUNCORECT_H
#define APP1_MODIFICARERASPUNCORECT_H

#include<iostream>
#include<fstream>

void modificareVariantaCorecta(std::string varCorecta){
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

    test.setRaspCorect(exNr,varCorecta);

    std::fstream gout(pathToTest);
    gout<<test;
    gout.close();

    std::fstream nout(pathToTest, std::ios::app);
    for(int i =0;i<10;i++){
        nout<<test.getStats()[i]<<" ";
    }
    nout.close();

    std::cout<<"\nRaspunsul corect pentru exercitiul "<< exNr<<" a fost modificat cu succes!\n";
}

#endif //APP1_MODIFICARERASPUNCORECT_H
