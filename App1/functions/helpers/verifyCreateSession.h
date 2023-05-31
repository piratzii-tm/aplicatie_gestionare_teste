//
// Created by Poe on 31.05.2023.
//

#ifndef APP1_VERIFYCREATESESSION_H
#define APP1_VERIFYCREATESESSION_H

#include<iostream>
#include<fstream>
#include<string>

bool verifyCreateSession(){
    std::ifstream fin("../files/creationTest.txt");
    std::string testId;
    std::getline(fin,testId,'\n');
    if(testId == ""){return true;}
    return false;
}

#endif //APP1_VERIFYCREATESESSION_H
