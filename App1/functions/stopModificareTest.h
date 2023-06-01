//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_STOPMODIFICARETEST_H
#define APP1_STOPMODIFICARETEST_H
#include<iostream>
#include<fstream>

void stopModificareTest(){
    std::ofstream fout("../files/modifyExercise.txt");
    fout<<"";
    fout.close();
    std::ofstream gout("../files/modifyTest.txt");
    gout<<"";
    gout.close();
    std::cout<<"\nS-a oprit modificare testului!";
}

#endif //APP1_STOPMODIFICARETEST_H
