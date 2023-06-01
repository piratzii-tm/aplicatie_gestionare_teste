//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_VERIFYEDITSESSION_H
#define APP1_VERIFYEDITSESSION_H
#include<iostream>
#include<fstream>
#include<string>

bool verifyEditSession(){
    std::ifstream fin("../files/modifyTest.txt");
    std::string testId;
    std::getline(fin,testId,'\n');
    if(testId == ""){return true;}
    return false;
}

#endif //APP1_VERIFYEDITSESSION_H
