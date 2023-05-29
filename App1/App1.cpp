#include<iostream>
#include<cstring>

#include "./functions/login.h"
#include "./functions/logout.h"
#include "./functions/vizualizareProfil.h"

int main(int numberOfArguments, char **arguments) {

    if(numberOfArguments == 1){
        std::cout<<"\n";
        std::cout<<"Buna ziua, pentru a descoperi comenzile pozibile va rog sa va logati folosind: \n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>' \n\n";
        std::cout<<"Tot ce se afla intre <...> trebuie inlocuit cu textul aferent, restul comenzilor trebuind respectate cu strictete!\n";
        return 0;
    }
    if(numberOfArguments == 3 && strcmp(arguments[1],"logare") == 0){
        std::string name = arguments[2];
        login(name);
        return 0;
    }
    if(numberOfArguments == 2 && strcmp(arguments[1],"delogare") == 0){
        logout();
        return 0;
    }
    if(numberOfArguments == 2 && strcmp(arguments[1], "vizualizare_profil") == 0){
        vizualizare_profil();
        return 0;
    }

    std::cout<<"\nComanda adaugata nu exista! Mai incercati.\n--"<<arguments[1]<<"--";

}