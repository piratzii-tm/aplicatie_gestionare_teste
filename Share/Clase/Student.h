#include <iostream>
#include <string>
#include <list>

using namespace std;

#ifndef TESTE_PP_STUDENT_H
#define TESTE_PP_STUDENT_H

class Student {
    string nume;
    int nrTesteDate;
    list<string> idTesteDate;
    list<int> notaTeste;
public:
    Student();
    Student(string);
    void afis();
    void addTest(string, int);
};

#endif