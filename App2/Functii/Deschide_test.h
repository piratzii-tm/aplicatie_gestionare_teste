#include <iostream>
#include <fstream>

#ifndef DESCHIDE_TEST_H
#define DESCHIDE_TEST_H


void deschide_test(std::string idTest){

    //Se verifica daca exista student logat

    std::ifstream fin_student(LOGARE_FILE_NAME);

    std::string nume_conectat;

    if(getline(fin_student, nume_conectat)){
        fin_student.close();
    }else{
        std::cout << "ELEV NECONECTAT";
        fin_student.close();
        return;
    }

    //Verifica daca exista fisierul cu textul
    std::string FISIER_TEST_CAUTAT = "../../Share/Fisiere/Teste/" + idTest + ".txt";
    std::string FISIER_TEST_CURENT = "../../Share/Fisiere/Teste/Test_Curent.txt";

    std::ifstream fin_test(FISIER_TEST_CAUTAT);
    std::string nume_test, nrExercitii, intrebare, var, var_cor;


    if(getline(fin_test, nume_test)){
        //Daca testul exista Incepem testul si afisam prima intrebare

        std::cout << "   TESTUL A INCEPUT\n\n";

        getline(fin_test, nrExercitii);

        getline(fin_test, intrebare);
        std::cout << intrebare << '\n';

        for(int i = 0; i < 4; i++){
            getline(fin_test, var);

            switch(i){
                case 0: std::cout<< "a) "; break;
                case 1: std::cout<< "b) "; break;
                case 2: std::cout<< "c) "; break;
                case 3: std::cout<< "d) "; break;
                default: std::cout<< "CEVA NU E OK";
            }

            std::cout << var << " ";
        }

        getline(fin_test, var); //citim varianta corecta ca sa trecem peste ea
        std::cout << '\n';

        //Scriem fisierul cu testul curent cu restul de intrebari ramase
        std::ofstream fout_curent_test(FISIER_TEST_CURENT);
        fout_curent_test << nume_test << '\n';

        int nrEx = stoi(nrExercitii);
        nrEx--;
        fout_curent_test << nrEx << '\n';

        for(int i = 0; i < nrEx; i++){
            getline(fin_test, intrebare);
            fout_curent_test << intrebare << '\n';

            for(int j = 0; j < 5; j++){ // pana la 5 pentru ca luam si varianta corecta
                getline(fin_test, var);
                fout_curent_test << var << '\n';
            }

        }


        fout_curent_test.close();
        fin_test.close();
    }else{
        std::cout << "ACEST TEST NU EXISTA";
        fin_test.close();
        return;
    }




}

#endif //APP2_DESCHIDE_TEST_H
