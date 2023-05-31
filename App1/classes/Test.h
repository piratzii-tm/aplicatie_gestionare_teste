//
// Created by Poe on 31.05.2023.
//

#ifndef APP1_TEST_H
#define APP1_TEST_H

#include<iostream>
#include<string>
#include<vector>
#include  "Exercitiu.h"


class Test {
    std::string testId;
    int nrDeExercitii;
    std::vector<Exercitiu> listaExercitii;
    std::vector<int> statistica;
public:
    Test(){}
    Test(std::string,int);
    void adaugareExercitiu(const Exercitiu&);
    std::string getId(){return this->testId;}

    friend std::ostream& operator <<(std::ostream&, const Test&);
    friend std::istream& operator >>(std::istream&, Test&);

    void afisareProfil(int);
};


#endif //APP1_TEST_H
