//
// Created by Iulian on 5/29/2023.
//

#ifndef APP1_VIZUALIZAREPROFIL_H
#define APP1_VIZUALIZAREPROFIL_H

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

void vizualizare_profil(){
    std::ifstream fin("../../Share/Fisiere/Profesor_logat.txt");
    std::string nameOfLoggedProfessor;
    std::getline(fin, nameOfLoggedProfessor, '\n');
    fin.close();

    std::replace(nameOfLoggedProfessor.begin(), nameOfLoggedProfessor.end(), ' ', '_');
    std::string nameOfProfessorFile = "../../Share/Fisiere/Profesori/"+nameOfLoggedProfessor+".txt";
    
    std::string name;
    int numberOfTestsCreated;
    // Test **listOfProfesorTests;

    std::ifstream gin(nameOfProfessorFile);
    std::getline(gin, name, '\n');
    gin>>numberOfTestsCreated;



    if(numberOfTestsCreated == 0){
        std::cout<<"\nNumele profesorului: "<<name<<"\n";
        std::cout<<"Numarul testelor create:"<<numberOfTestsCreated<<"\n";
        std::cout<<"Pentru a crea un test introduceti comanda: \n\n";
        std::cout<<" ./App1.exe creare_test <id_test_de_creat> <nr_intrebari>\n\n";
    }else{
        return;
        //se vor citi datele pentru fiecare test si se vor crea pe rand clasele cu teste
        //apoi se va crea clasa profesor si se va afisa
    }

}

#endif //APP1_VIZUALIZAREPROFIL_H
