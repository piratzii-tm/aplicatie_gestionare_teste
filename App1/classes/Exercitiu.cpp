//
// Created by Poe on 31.05.2023.
//

#include "Exercitiu.h"
#include<iostream>
#include<string>
#include<vector>

Exercitiu::Exercitiu(std::string cerinta, std::vector<std::string> raspunsuri, std::string raspCorect){
    this->cerinta = cerinta;
    this->variantaCorecta = raspCorect;
    for(int i=0;i<raspunsuri.size();i++){
        this->raspunsuri.push_back(raspunsuri[i]);
    }
}

std::ostream& operator <<(std::ostream& gout, const Exercitiu& exerciseToWrite){
    gout<<exerciseToWrite.cerinta<<"\n";
    for(int i=0;i<exerciseToWrite.raspunsuri.size();i++){
        gout<<exerciseToWrite.raspunsuri[i]<<"\n";
    }
    gout<<exerciseToWrite.variantaCorecta;
    return gout;
}

std::istream& operator >>(std::istream& gin, Exercitiu& deCitit){
    std::string aux;
    std::getline(gin, aux, '\n');
    if(aux!=""){
        deCitit.cerinta = aux;
        for(int i=0;i<4;i++){
            std::getline(gin, aux, '\n');
            deCitit.raspunsuri.push_back(aux);
        }
        std::getline(gin,deCitit.variantaCorecta,'\n');
    }
    return gin;
}

void Exercitiu::afisareProfil(int j) {
    char letter[5] = "abcd";
    std::cout<<"| Ex."<<j+1<<" |\n"<<this->cerinta<<"\n";
    std::cout<<"Raspunsuri:\n";
    for(int k=0;k<4;k++){
        std::cout<<letter[k]<<")"<<this->raspunsuri[k]<<"\n";
    }
    std::cout<<"Varianta corecta: "<<this->variantaCorecta<<"\n";
}

void Exercitiu::setEnunt(std::string enuntNou) {
    this->cerinta = enuntNou;
}
void Exercitiu::setRaspCorect(std::string raspuns) {
    this->variantaCorecta = raspuns;
}

void Exercitiu::setRaspuns(int nrRaspuns, std::string raspuns) {
    for(int i=0;i<4;i++){
        if(i == nrRaspuns){
            this->raspunsuri[i] = raspuns;
        }
    }
}