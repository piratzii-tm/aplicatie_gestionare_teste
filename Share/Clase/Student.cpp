#include "Student.h"

Student::Student() {
    this->nume = "unknown";
    this->nrTesteDate = 0;
}

Student::Student(std::string nume) {
    this->nume = nume;
    this->nrTesteDate = 0;
}

void Student::afis() {
    std::cout << "Nume: " << this->nume << '\n';
    std::cout << "Numar e teste: " << this->nrTesteDate << '\n';
    std::cout << "Test si nota: \n";
    std::list<std::string>::iterator testIte;
    std::list<int>::iterator notaIte;
    for(testIte = this->idTesteDate.begin(), notaIte = this->notaTeste.begin();
        testIte != this->idTesteDate.end(); testIte++, notaIte++){
        std::cout << *testIte << " -> " << *notaIte << '\n';
    }
}

void Student::addTest(std::string idTest, int nota) {
    this->nrTesteDate++;
    this->idTesteDate.push_back(idTest);
    this->notaTeste.push_back(nota);
}