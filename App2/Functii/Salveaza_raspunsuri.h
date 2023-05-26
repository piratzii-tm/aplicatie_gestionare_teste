#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <list>
#include <cmath>
#include "../Variabile.h"

#ifndef APP2_SALVEAZA_RASPUNSURI_H
#define APP2_SALVEAZA_RASPUNSURI_H

int calcNota(std::list<char>, std::list<char>, int);
void adaugaStatisticaTest(std::string, int, int);

void salveaza_raspunsuri(){

    std::string nrExercitii, nume_test, nume_student;
    int nrEx;
    std::list<char> lista_raspunsuri, lista_grila;
    int notaFinala;

    std::string aux;//variabila care sa ma ajute sa sar de informatia de care nu am nevoie din fisier


    std::ifstream fin;

    //citire nume student care a dat testul
    fin.open(LOGARE_FILE_NAME);
    getline(fin, nume_student);
    fin.close();

    //citire numele testului care a fost dat
    fin.open(FILE_TEST_CURENT);
    getline(fin, nume_test);
    fin.close();

    //gasirea in testul original a restului de informatii
    std::string nume_file_original_test_curent = "../../Share/Fisiere/Teste/" + nume_test + ".txt";

    fin.open(nume_file_original_test_curent);
    getline(fin, aux); //nume test
    getline(fin, nrExercitii); //nrExercitii
    nrEx = stoi(nrExercitii);

    for(int i = 0; i < nrEx; i++){
        getline(fin, aux); //cerinta
        for(int j = 0; j < 4; j++) {
            getline(fin, aux); //cele 4 variante
        }
        getline(fin, aux); // varianta corecta

        lista_grila.push_back(aux[0]);
    }
    fin.close();

    //citire lista de raspunsuri date la acest test
    fin.open(FILE_RASPUNSURI_TEST_CURENT);
    for(int i = 0; i < nrEx; i++){
        getline(fin, aux); //raspuns la fiecare exercitiu
        lista_raspunsuri.push_back(aux[0]);
    }
    fin.close();


    std::ofstream fout;

    //Resetam fisierul cu raspunsurile date
    fout.open(FILE_RASPUNSURI_TEST_CURENT);
    fout << "";
    fout.close();

    //Resetare fisierul cu testul curent
    fout.open(FILE_TEST_CURENT);
    fout << "";
    fout.close();

    //Calculeaza nota finala
    notaFinala = calcNota(lista_raspunsuri, lista_grila, nrEx);

    std::cout << "FELICITARI!\n";
    std::cout << "NOTA: " << notaFinala << '\n';
    adaugaStatisticaTest(nume_test, notaFinala, nrEx);//modifica statisticile testului
}

int calcNota(std::list<char> myRespons, std::list<char> grila, int nrExer){
    double pct_exercitiu = (10.0 / nrExer);
    double pct_acumulate = 0.0;

    std::list<char>::iterator myRespIte;
    std::list<char>::iterator grilaIte;

    for(myRespIte = myRespons.begin(), grilaIte = grila.begin(); myRespIte != myRespons.end(); myRespIte++, grilaIte++){
        if(*myRespIte == *grilaIte){
            pct_acumulate += pct_exercitiu;
        }
    }

    return round(pct_acumulate);
}

void adaugaStatisticaTest(std::string numeTest, int nota, int nrExer){
    std::string locatie_fisier = "../../Share/Fisiere/Teste/" + numeTest + ".txt"; //locatia fisierului

    std::string aux; //centru a citii datele din fisier
    std::string sirStatistica; //string-ul cu statistica veche

    //cipiez totul inafara de statistica in fisierul auxiliar
    std::ifstream fin_test(locatie_fisier);
    std::ofstream fout_aux(FILE_AUX);

    getline(fin_test, aux);//nume test
    fout_aux << aux << '\n';
    getline(fin_test, aux);//nr de teste
    fout_aux << aux << '\n';

    for(int i = 0; i < nrExer; i++){
        getline(fin_test, aux);//intrebare
        fout_aux << aux << '\n';

        for(int j = 0; j < 5; j++){
            getline(fin_test, aux);//cele 4 variante + varianta corecta
            fout_aux << aux << '\n';
        }
    }

    getline(fin_test, sirStatistica); // sirul de statistica vechi


    //Se modeleaza sirul de statististici

    for(int i = 0; i < 10; i++){
        if((i+1) == nota){
            char notaAux = sirStatistica[i * 2];
            int notaint = int(notaAux - '0') + 1;

            fout_aux << std::to_string(notaint);
        }else{
            fout_aux << sirStatistica[i * 2];
        }
        fout_aux << " ";
    }
    fout_aux << '\n';

    fout_aux.close();
    fin_test.close();

    //rescriem testul cu statistica corecta

    std::ifstream fin_aux(FILE_AUX);
    std::ofstream fout_test(locatie_fisier);

    while(getline(fin_aux, aux)){
        fout_test << aux << '\n';
    }

    fout_test.close();
    fin_aux.close();


    //stergem tot din aux

    fout_aux.open(FILE_AUX);
    fout_aux << "";
    fout_aux.close();

}

#endif //APP2_SALVEAZA_RASPUNSURI_H
