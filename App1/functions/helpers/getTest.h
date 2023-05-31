//
// Created by Poe on 31.05.2023.
//

#ifndef APP1_GETTEST_H
#define APP1_GETTEST_H

#include "../../classes/Test.h"
#include<string>
#include<fstream>

Test getTest(const std::string& testId){
    std::string testPath = "../../Share/Fisiere/Teste/"+testId+".txt";
    std::ifstream fin(testPath);
    Test newTest;
    fin>>newTest;
    fin.close();
    return newTest;
}

#endif //APP1_GETTEST_H
