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
    Test(const Test&);
    void adaugareExercitiu(const Exercitiu&);
    std::string getId(){return this->testId;}
    void afisareProfil(int);
    std::vector<int> getStats(){return this->statistica;}
    void setEnunt(int nrEx, std::string enuntNou);
    void setRaspCorect(int nrEx, std::string raspuns);
    void setRaspuns(int nrEx, int nrRasp, std::string raspuns);

    friend std::ostream& operator <<(std::ostream&, const Test&);
    friend std::istream& operator >>(std::istream&, Test&);


};


#endif //APP1_TEST_H
