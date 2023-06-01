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
    for(int i=0;i<=deCitit.nrDeExercitii;i++){
        Exercitiu aux;
        gin>>aux;
        if(!aux.getCerinta().empty()){deCitit.listaExercitii.push_back(aux);}
    }
    if(deCitit.listaExercitii.size() == deCitit.nrDeExercitii){
        for(int i=0;i<10;i++){
            int a;
            gin>>a;
            deCitit.statistica.push_back(a);
        }
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

Test::Test(const Test&decopiat){
    this->testId = decopiat.testId;
    this->nrDeExercitii = decopiat.nrDeExercitii;
    for(int i=0;i<decopiat.nrDeExercitii;i++){
        this->listaExercitii.push_back(decopiat.listaExercitii[i]);
    }
    for(int i=0;i<10;i++){
        this->statistica.push_back(decopiat.statistica[i]);
    }
}

void Test::setEnunt(int nrEx, std::string enuntNou) {
    for(int i=0;i<this->nrDeExercitii;i++){
        if(i == nrEx-1){
            this->listaExercitii[i].setEnunt(enuntNou);
        }
    }
}

void Test::setRaspCorect(int nrEx, std::string raspuns) {
    for(int i=0;i<this->nrDeExercitii;i++){
        if(i == nrEx-1){
            this->listaExercitii[i].setRaspCorect(raspuns);
        }
    }
}

void Test::setRaspuns(int nrEx, int nrRasp, std::string raspuns) {
    for(int i=0;i<this->nrDeExercitii;i++){
        if(i == nrEx-1){
            this->listaExercitii[i].setRaspuns(nrRasp,raspuns);
        }
    }
}