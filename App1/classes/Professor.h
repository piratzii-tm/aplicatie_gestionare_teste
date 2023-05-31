//
// Created by Poe on 31.05.2023.
//

#ifndef APP1_PROFESSOR_H
#define APP1_PROFESSOR_H

#include<iostream>
#include<string>
#include<vector>
#include "Test.h"

class Professor {
    std::string nume;
    int nrTestCreate;
    std::vector<std::string> listaTeste;
public:
    Professor(){}

    friend std::istream& operator >>(std::istream&, Professor&);
    friend std::ostream& operator <<(std::ostream&, const Professor&);

    void incrementNrTeste(){this->nrTestCreate++;}
    void addCreatedTest(const std::string);
    void afisareProfil();
};


#endif //APP1_PROFESSOR_H
