#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "../Variabile.h"
#include "Salveaza_raspunsuri.h"

#ifndef APP2_RASPUNS_INTREBARE_H
#define APP2_RASPUNS_INTREBARE_H


void raspuns_intrebare(const std::string& myRaspuns){

    std::string raspuns = myRaspuns;
    std::transform(raspuns.begin(), raspuns.end(), raspuns.begin(), ::tolower);

    //verificam daca raspunsul este unul corect
    if(raspuns != "a" && raspuns != "b" && raspuns != "c" && raspuns != "d"){
        std::cout << "RASPUNS POSIBIL: a, b, c, d\n";
        return;
    }

    std::string nume_test, nrExercitii, intrebare, var;

    std::ifstream fin_test_curent(FILE_TEST_CURENT);

    //verificam daca avem vre-un test pornit
    if(getline(fin_test_curent, nume_test)){
        //daca DA,
        getline(fin_test_curent, nrExercitii);

        std::ofstream append_raspunsuri_curent(FILE_RASPUNSURI_TEST_CURENT, std::ios_base::app);
        int nrEx = stoi(nrExercitii);

        append_raspunsuri_curent << raspuns << "\n"; //apendui rezultatul in fisierul de rezultate
        append_raspunsuri_curent.close();

        if(nrEx > 0){ //daca inca nu e ultima intrebare
            getline(fin_test_curent, intrebare);
            std::cout << intrebare << '\n';

            for(int i = 0; i < 4; i++){
                getline(fin_test_curent, var);

                switch(i){
                    case 0: std::cout<< "a) "; break;
                    case 1: std::cout<< "b) "; break;
                    case 2: std::cout<< "c) "; break;
                    case 3: std::cout<< "d) "; break;
                    default: std::cout<< "CEVA NU E OK";
                }

                std::cout << var << " ";
            }

            getline(fin_test_curent, var); //citim varianta corecta ca sa trecem peste ea
            std::cout << '\n';

            //Scriem intr-un fisier auxiliar intrebarile care au ramas
            std::ofstream fout_aux(FILE_AUX);
            fout_aux << nume_test << '\n';
            nrEx--;
            fout_aux << nrEx << '\n';

            for(int i = 0; i < nrEx; i++){
                getline(fin_test_curent, intrebare);
                fout_aux << intrebare << "\n";

                for(int j = 0; j < 5; j++){
                    getline(fin_test_curent, var);
                    fout_aux << var << '\n';
                }
            }
            fout_aux.close();
            fin_test_curent.close();

            //copiem inapoi in fisierul Test_curent.txt

            std::ifstream fin_aux(FILE_AUX);
            std::ofstream fout_Curent_test(FILE_TEST_CURENT);

            getline(fin_aux, nume_test);
            fout_Curent_test << nume_test << '\n';

            getline(fin_aux, nrExercitii);
            fout_Curent_test << nrExercitii << '\n';
            nrEx = stoi(nrExercitii);

            for(int i = 0; i < nrEx; i++){
                getline(fin_aux, intrebare);
                fout_Curent_test << intrebare << '\n';

                for(int j = 0; j < 5; j++){
                    getline(fin_aux, var);
                    fout_Curent_test << var << '\n';
                }
            }

            fout_Curent_test.close();
            fin_aux.close();

            //resetam fisierul auxiliar
            fout_aux.open(FILE_AUX);
            fout_aux << "";
            fout_aux.close();


        }else{ //daca e ultima intrebare
            salveaza_raspunsuri();
        }

    }else{
        std::cout << "NU ESTE PORNIT NICI UN TEST\n";
        fin_test_curent.close();
        return;
    }

}

#endif //APP2_RASPUNS_INTREBARE_H
