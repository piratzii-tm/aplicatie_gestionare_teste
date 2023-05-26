#include <iostream>
#include <string>
#include <list>

#ifndef TESTE_PP_STUDENT_H
#define TESTE_PP_STUDENT_H

class Student {
    std::string nume;
    int nrTesteDate;
    std::list<std::string> idTesteDate;
    std::list<int> notaTeste;
public:
    Student();
    Student(std::string);
    void afis();
    void addTest(std::string, int);
};

#endif