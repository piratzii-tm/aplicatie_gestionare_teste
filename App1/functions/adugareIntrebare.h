//
// Created by Poe on 31.05.2023.
//

#ifndef APP1_ADUGAREINTREBARE_H
#define APP1_ADUGAREINTREBARE_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "../classes/Exercitiu.h"
#include "../classes/Test.h"
#include "../classes/Professor.h"

void adaugaIntrebare(std::string enunt, std::vector<std::string> rasp, std::string varCorecta){
    Exercitiu newExercise(enunt, rasp, varCorecta);

    std::ifstream fin("../files/creationTest.txt");
    std::string testId;
    std::getline(fin,testId,'\n');
    fin.close();

    std::string pathOfTest = "../../Share/Fisiere/Teste/"+testId+".txt";
    std::ifstream gin(pathOfTest);

    Test testToAddQ;
    gin>>testToAddQ;
    gin.close();


    testToAddQ.adaugareExercitiu(newExercise);

    std::ofstream gout(pathOfTest);
    gout<<testToAddQ;
    gout.close();

    std::ifstream hin("../files/creationTest.txt");
    std::string testIdH;
    int total,current;
    std::getline(hin, testIdH, '\n');
    hin>>total>>current;
    hin.close();

    current++;
    std::ofstream hout("../files/creationTest.txt");

    if(current == total){
        hout<<"";
        std::cout<<"\nAi adaugat toate intrebarile!\n";

        std::string loggedProf;
        std::ifstream pin("../../Share/Fisiere/Profesor_logat.txt");
        std::getline(pin,loggedProf,'\n');
        pin.close();

        std::replace(loggedProf.begin(), loggedProf.end(),' ','_');
        std::string pathToFileProf = "../../Share/Fisiere/Profesori/"+loggedProf+".txt";

        std::ifstream uin(pathToFileProf);
        Professor prof;
        uin>>prof;
        prof.incrementNrTeste();
        prof.addCreatedTest(testId);
        uin.close();

        std::ofstream uout(pathToFileProf);
        uout<<prof;
        uout.close();

        std::ofstream vout(pathOfTest,std::ios::app);
        for(int i=0;i<10;i++){
            vout<<"0 ";
        }
        vout.close();
    }else{
        hout<<testIdH<<"\n"<<total<<"\n"<<current;
    }
    hout.close();


}

#endif //APP1_ADUGAREINTREBARE_H
