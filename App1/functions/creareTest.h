//
// Created by Poe on 31.05.2023.
//

#ifndef APP1_CREARETEST_H
#define APP1_CREARETEST_H

#include<iostream>
#include<string>
#include<fstream>
#include "../classes/Test.h"

void creareTest(std::string testId, int nrExercitii){
    Test newTest(testId, nrExercitii);

    std::string newTestFileName = "../../Share/Fisiere/Teste/"+testId+".txt";
    std::ofstream fout(newTestFileName);
    fout<<newTest;
    fout.close();

    std::ofstream hout("../files/creationTest.txt");
    hout<<testId<<"\n";
    hout<<nrExercitii<<"\n";
    hout<<0;
    hout.close();

    std::cout<<"\nAti inceput o sesiune de creareare test.\n";
    std::cout<<"Id test: "<<testId<<" Nr exercitii: "<<nrExercitii<<"\n";
    std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
    std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
    std::cout<<"COMANDA TREBUIE RULATA PENTRU FIECARE EXERCITIU IN PARTE!\n";
}

#endif //APP1_CREARETEST_H
