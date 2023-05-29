//
// Created by Iulian on 5/29/2023.
//

#ifndef APP1_FILEEXISTS_H
#define APP1_FILEEXISTS_H

#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>

bool fileExists(std::string name){
    std::ifstream file;
    std::replace( name.begin(), name.end(), ' ', '_');
    std::string nameOfFile = "../../Share/Fisiere/Profesori/" + name + ".txt";
    file.open(nameOfFile);
    if(file){
        return true;
    }
    return false;
}

#endif //APP1_FILEEXISTS_H
