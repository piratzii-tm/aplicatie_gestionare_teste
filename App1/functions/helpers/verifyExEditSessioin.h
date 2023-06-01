//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_VERIFYEXEDITSESSIOIN_H
#define APP1_VERIFYEXEDITSESSIOIN_H

#include<iostream>
#include<fstream>
#include<string>

bool verifyExEditSession(){
    std::ifstream fin("../files/modifyExercise.txt");
    std::string testId;
    std::getline(fin,testId,'\n');
    if(testId == ""){return true;}
    return false;
}

#endif //APP1_VERIFYEXEDITSESSIOIN_H
