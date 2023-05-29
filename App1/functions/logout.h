//
// Created by Iulian on 5/29/2023.
//

#ifndef APP1_LOGOUT_H
#define APP1_LOGOUT_H

#include<fstream>
#include<iostream>
#include<string>

void logout(){
    std::ifstream fin("../../Share/Fisiere/Profesor_logat.txt");
    std::string name;
    std::getline(fin,name,'\n');
    std::cout<<"\n La revedere, "<<name<<"! \n";
    fin.close();

    std::ofstream fout("../../Share/Fisiere/Profesor_logat.txt");
    fout<<"";
    fout.close();

}


#endif //APP1_LOGOUT_H
