//
// Created by Poe on 31.05.2023.
//

#include "Test.h"
#include<iostream>
#include<string>
#include<vector>
#include "Exercitiu.h"

Test::Test(std::string testId, int nrEx):testId(testId), nrDeExercitii(nrEx){
    for(int i=0;i<10;i++){
        this->statistica.push_back(0);
    }
}

void Test::adaugareExercitiu(const Exercitiu &exNou) {
    this->listaExercitii.push_back(exNou);
}

std::ostream& operator <<(std::ostream& gout, const Test& testToWrite){
    gout<<testToWrite.testId<<"\n";
    gout<<testToWrite.nrDeExercitii<<"\n";
    for(int i=0;i<testToWrite.listaExercitii.size();i++){
        gout<<testToWrite.listaExercitii[i]<<"\n";
    }
    return gout;
}

std::istream& operator >>(std::istream& gin, Test& deCitit){
    std::getline(gin,deCitit.testId,'\n');
    gin>>deCitit.nrDeExercitii;
    for(int i=0;i<deCitit.nrDeExercitii;i++){
        Exercitiu aux;
        gin>>aux;
        if(aux.getCerinta()!=""){deCitit.listaExercitii.push_back(aux);}
    }
    for(int i=0;i<10;i++){
        deCitit.statistica.push_back(0);
    }
    return gin;
}

void Test::afisareProfil(int i) {
    std::cout<<"\n\n ----- TEST "<<i+1<<" ----- \n\n";
    std::cout<<"ID test: "<<this->testId;
    std::cout<<"\nNr. exercitii: "<<this->nrDeExercitii<<"\n\n";
    for(int j=0;j<this->listaExercitii.size();j++){
        this->listaExercitii[j].afisareProfil(j);
        std::cout<<"\n";
    }
}