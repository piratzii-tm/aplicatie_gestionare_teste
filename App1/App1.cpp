#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<fstream>

#include "./functions/login.h"
#include "./functions/logout.h"
#include "./functions/vizualizareProfil.h"
#include "./functions/creareTest.h"
#include "./functions/adugareIntrebare.h"
#include "./functions/statisticiTest.h"
#include "./functions/modificareTest.h"
#include "./functions/modificareExercitiu.h"
#include "./functions/afisVariantaCurenta.h"
#include "./functions/stopModificareExercitiu.h"
#include "./functions/stopModificareTest.h"
#include "./functions/modificareEnunt.h"
#include "./functions/modificareRaspunCorect.h"
#include "./functions/modificareRaspuns.h"

#include "./functions/helpers/verifyCreateSession.h"
#include "./functions/helpers/verifyEditSession.h"
#include "./functions/helpers/verifyExEditSessioin.h"
#include "./functions/helpers/verifyLoggedProf.h"

int main(int numberOfArguments, char **arguments) {
    if(numberOfArguments == 1){
        if(verifyCreateSession() && verifyEditSession()){
            std::ifstream fin("../../Share/Fisiere/Profesor_logat.txt");
            std::string name;
            std::getline(fin,name,'\n');
            if(!name.empty()){
                std::cout<<"\n\nComenzile posibile sunt:\n\n";
                std::cout<<" ./App1.exe vizulizare_profil\n";
                std::cout<<" ./App1.exe creare_test <id_test_de_creat> <nr_intrebari>\n";
                std::cout<<" ./App1.exe modificare_test <id_test>\n";
                std::cout<<" ./App1.exe vizualizare_statistici <id_test>\n";
                std::cout<<" ./App1.exe delogare\n";
                return 0;
            }

            std::cout<<"\n";
            std::cout<<"Buna ziua, pentru a descoperi comenzile posibile va rog sa va logati folosind: \n\n";
            std::cout<<" ./App1.exe logare '<nume_profesor>' \n\n";
            std::cout<<"Tot ce se afla intre <...> trebuie inlocuit cu textul aferent, restul comenzilor trebuind respectate cu strictete!\n";
            return 0;
        } else if(!verifyEditSession()){
            std::cout<<"\n Te afli intr-o sesiune de editare test! Nu se pot accesa alte comenzi decat cele specificate anterior!\n";
            return 0;
        }
        std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
        std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
        std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
        return 0;

    }
    if(numberOfArguments == 3 && strcmp(arguments[1],"logare") == 0){
        if(verifyLoggedProf()){
            std::string name = arguments[2];
            login(name);
            return 0;
        }
        std::cout<<"\nSunteti deja logat cu un cont. Folositi urmatoarea comanda pentru a va deconecta:\n\n";
        std::cout<<" ./App1.exe delogare\n";
        return 0;
    }
    if(numberOfArguments == 2 && strcmp(arguments[1],"delogare") == 0){
        if(!verifyLoggedProf()){
            if(verifyCreateSession() && verifyEditSession()){
                logout();
                return 0;
            } else if(!verifyEditSession()){
                std::cout<<"\n Te afli intr-o sesiune de editare test! Nu se pot accesa alte comenzi decat cele specificate anterior!\n";
                return 0;
            }
            std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
            std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 2 && strcmp(arguments[1], "vizualizare_profil") == 0){
        if(!verifyLoggedProf()){
            if(verifyCreateSession() && verifyEditSession()){
                vizualizare_profil();
                return 0;
            } else if(!verifyEditSession()){
                std::cout<<"\n Te afli intr-o sesiune de editare test! Nu se pot accesa alte comenzi decat cele specificate anterior!\n";
                return 0;
            }
            std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
            std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 4 && strcmp(arguments[1], "creare_test") == 0){
        if(!verifyLoggedProf()){
            if(verifyCreateSession() && verifyEditSession()){
                std::string testId = arguments[2];
                std::string nr = arguments[3];
                int nrExercitii = stoi(nr);
                creareTest(testId,nrExercitii);
                return 0;
            } else if(!verifyEditSession()){
                std::cout<<"\n Te afli intr-o sesiune de editare test! Nu se pot accesa alte comenzi decat cele specificate anterior!\n";
                return 0;
            }
            std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
            std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 8 && strcmp(arguments[1], "adaugare_intrebare") == 0){
        if(!verifyLoggedProf()){
            if(!verifyCreateSession()){
                std::string enunt = arguments[2];
                std::replace(enunt.begin(), enunt.end(),'\'','\0');
                std::string aux;
                std::vector<std::string> raspunsuri;
                for(int i=3;i<7;i++){
                    aux = arguments[i];
                    std::replace(aux.begin(), aux.end(),'\'','\0');
                    raspunsuri.push_back(aux);
                }
                std::string raspCorect;
                raspCorect = arguments[7];
                adaugaIntrebare(enunt, raspunsuri, raspCorect);
                return 0;
            }
            std::cout<<"\n Nu te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 3 && strcmp(arguments[1], "vizualizare_statistici")==0){
        if(!verifyLoggedProf()){
            if(verifyEditSession()&&verifyCreateSession()){
                std::string aux = arguments[2];
                statisticiTest(aux);
                return 0;
            } else if(!verifyEditSession()){
                std::cout<<"\n Te afli intr-o sesiune de editare test! Nu se pot accesa alte comenzi decat cele specificate anterior!\n";
                return 0;
            }
            std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
            std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
            return 0;
        }
        if(numberOfArguments == 3 && strcmp(arguments[1],"modificare_test")==0){
            if(verifyEditSession() && verifyCreateSession()){
                modificareTest(arguments[2]);
                return 0;
            } else if(!verifyEditSession()){
                std::cout<<"\n Te afli intr-o sesiune de editare test! Nu se pot accesa alte comenzi decat cele specificate anterior!\n";
                return 0;
            }
            std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
            std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 3 && strcmp(arguments[1],"modificare_test")==0){
        if(!verifyLoggedProf()){
            if(verifyEditSession() && verifyCreateSession()){
                modificareTest(arguments[2]);
                return 0;
            } else if(!verifyEditSession()){
                std::cout<<"\n Te afli intr-o sesiune de editare test! Nu se pot accesa alte comenzi decat cele specificate anterior!\n";
                return 0;
            }
            std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
            std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 3 && strcmp(arguments[1],"modificare_exercitiu")==0){
        if(!verifyLoggedProf()){
            if(verifyCreateSession() && !verifyEditSession()){
                modificareExercitiu(arguments[2]);
                return 0;
            }else if(verifyEditSession()){
                std::cout<<"\nNu te afli intr-o sesiunde de editare test.\n";
                return 0;
            }
            std::cout<<"\n Te afli intr-o sesiune de creare test! Nu se pot accesa alte comenzi!\n";
            std::cout<<"Pentru a adauga exercitii testului rulati comanda de mai jos:\n\n";
            std::cout<<"./App1.exe adaugare_intrebare '<enunt>' '<raspuns1>' '<raspuns2>' '<raspuns3>' '<raspuns4>' <a/b/c/d>\n\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 2 && strcmp(arguments[1], "afiseaza_varianta_curenta")==0){
        if(!verifyLoggedProf()){
            if(!verifyEditSession() && verifyCreateSession()){
                afisVariantaCurenta();
                return 0;
            }
            std::cout<<"\nAceasta comanda nu se poate accesa decat intr-o sesiune de editare test\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 2 && strcmp(arguments[1], "stop_modificare_exercitiu")==0){
        if(!verifyLoggedProf()){
            if(!verifyExEditSession()){
                stopModificareExercitiu();
                return 0;
            }

            std::cout<<"\nNu te poti opri din modificat un exercitiu pe care nu ai inceput sa il modifici!\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 2 && strcmp(arguments[1], "stop_modificare_test")==0) {
        if(!verifyLoggedProf()){
            if(!verifyEditSession()){
                stopModificareTest();
                return 0;
            }
            std::cout<<"\n Nu te afli intr-o sesiunde de modificare test!\n";
            return 0;
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 3 && strcmp(arguments[1], "enunt")==0){
        if(!verifyLoggedProf()){
            if(!verifyExEditSession()){
                std::string enunt = arguments[2];
                std::replace(enunt.begin(), enunt.end(),'\'','\0');
                modificareEnunt(enunt);
                return 0;
            }else if(verifyExEditSession()){
                std::cout<<"\nNu modifici niciun exercitiu in momentul actual!\n";
                return 0;
            }
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 3 && strcmp(arguments[1], "varianta_corecta")==0){
        if(!verifyLoggedProf()){
            if(!verifyExEditSession()){
                std::string rasp = arguments[2];
                std::replace(rasp.begin(), rasp.end(),'\'','\0');
                modificareVariantaCorecta(rasp);
                return 0;
            }else if(verifyExEditSession()){
                std::cout<<"\nNu modifici niciun exercitiu in momentul actual!\n";
                return 0;
            }
        }

        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    if(numberOfArguments == 4 && strcmp(arguments[1], "raspuns")==0){
        if(!verifyLoggedProf()){
            if(!verifyExEditSession()){
                std::string rasp = arguments[3];
                std::replace(rasp.begin(), rasp.end(),'\'','\0');
                modificareRaspuns(arguments[2],rasp);
                return 0;
            }else if(verifyExEditSession()){
                std::cout<<"\nNu modifici niciun exercitiu in momentul actual!\n";
                return 0;
            }
        }
        std::cout<<"\nNu sunteti logat! Folositi urmatoarea comanda pentru a va loga:\n\n";
        std::cout<<" ./App1.exe logare '<nume_profesor>'\n";
        return 0;
    }
    std::cout<<"\nComanda adaugata nu exista! Mai incercati.\n--"<<arguments[1]<<"--";

}