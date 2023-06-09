//
// Created by Poe on 31.05.2023.
//

#ifndef APP1_EXERCITIU_H
#define APP1_EXERCITIU_H

#include<iostream>
#include<string>
#include<vector>

class Exercitiu {

    std::string cerinta;
    std::vector<std::string> raspunsuri;
    std::string variantaCorecta;

public:
    Exercitiu(){}
    Exercitiu(std::string, std::vector<std::string>, std::string);
    std::string getCerinta(){return this->cerinta;}
    void afisareProfil(int);
    void setEnunt(std::string enuntNou);
    void setRaspCorect(std::string raspuns);
    void setRaspuns(int nrRaspuns, std::string raspuns);

    friend std::ostream& operator <<(std::ostream&, const Exercitiu&);
    friend std::istream& operator >>(std::istream&, Exercitiu&);


};


#endif //APP1_EXERCITIU_H
