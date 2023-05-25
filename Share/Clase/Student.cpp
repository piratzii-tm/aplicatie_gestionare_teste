#include "Student.h"

Student::Student() {
    this->nume = "unknown";
    this->nrTesteDate = 0;
}

Student::Student(string nume) {
    this->nume = nume;
    this->nrTesteDate = 0;
}

void Student::afis() {
    cout << "Nume: " << this->nume << '\n';
    cout << "Numar e teste: " << this->nrTesteDate << '\n';
    cout << "Test si nota: \n";
    list<string>::iterator testIte;
    list<int>::iterator notaIte;
    for(testIte = this->idTesteDate.begin(), notaIte = this->notaTeste.begin();
        testIte != this->idTesteDate.end(); testIte++, notaIte++){
        cout << *testIte << " -> " << *notaIte << '\n';
    }
}

void Student::addTest(string idTest, int nota) {
    this->nrTesteDate++;
    this->idTesteDate.push_back(idTest);
    this->notaTeste.push_back(nota);
}