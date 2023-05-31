//
// Created by Poe on 31.05.2023.
//

#include "Professor.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include "Test.h"
#include "../functions/helpers/getTest.h"

std::istream& operator >>(std::istream& gin, Professor& deCitit){
    std::getline(gin, deCitit.nume, '\n');
    gin>>deCitit.nrTestCreate;
    for(int i=0;i<deCitit.nrTestCreate;i++){
        std::string aux;
        gin>>aux;
        deCitit.listaTeste.push_back(aux);
    }
    return gin;
}

std::ostream& operator <<(std::ostream& gout, const Professor&prof){
    gout<<prof.nume<<"\n";
    gout<<prof.nrTestCreate<<"\n";
    for(int i=0;i<prof.nrTestCreate;i++){
        gout<<prof.listaTeste[i]<<"\n";
    }
    return gout;
}

void Professor::addCreatedTest(const std::string newTest) {
    this->listaTeste.push_back(newTest);
}

void Professor::afisareProfil() {
    std::cout<<"\nNumele profesorului: "<<this->nume<<"\n";
    std::cout<<"Numarul testelor create: "<<this->nrTestCreate;
    for(int i=0;i< this->nrTestCreate;i++){
        getTest(this->listaTeste[i]).afisareProfil(i);
    }
}