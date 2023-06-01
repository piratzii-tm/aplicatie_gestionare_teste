//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_STOPMODIFICAREEXERCITIU_H
#define APP1_STOPMODIFICAREEXERCITIU_H
#include<iostream>
#include<fstream>
void stopModificareExercitiu(){
    std::ofstream fout("../files/modifyExercise.txt");
    fout<<"";
    fout.close();

    std::cout<<"\nS-a oprit modificare exercitiului!";
}

#endif //APP1_STOPMODIFICAREEXERCITIU_H
