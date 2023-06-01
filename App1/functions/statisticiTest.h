//
// Created by Poe on 01.06.2023.
//

#ifndef APP1_STATISTICITEST_H
#define APP1_STATISTICITEST_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "../classes/Test.h"

void statisticiTest(std::string idTest){
    std::string testPath = "../../Share/Fisiere/Teste/"+idTest+".txt";
    std::ifstream fin(testPath);
    Test newTest;
    fin>>newTest;
    std::vector<int> stats;
    std::copy(newTest.getStats().begin(), newTest.getStats().end(), std::back_inserter(stats));
    std::cout<<"\nID test: "<<newTest.getId()<<"\n\n";
    for(int i=0;i<10;i++){
        std::cout<<stats[i]<<" elevi au obtinut nota "<<i+1<<"\n";
    }
    std::cout<<"\n\n";
    int max = 0;
    for(int i=0;i<10;i++){
        if(max<stats[i]){max=stats[i];}
        std::cout<<i+1<<" ";
    }
    std::cout<<"\n\n";
    for(int i=0;i<max;i++){
        for(int j=0;j<10;j++){
            if(stats[j]!=0){
                std::cout<<"+ ";
                stats[j]--;
            }else{std::cout<<"# ";}
        }
        std::cout<<"\n";
    }

}

#endif //APP1_STATISTICITEST_H
