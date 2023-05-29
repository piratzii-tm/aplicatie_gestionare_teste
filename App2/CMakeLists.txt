cmake_minimum_required(VERSION 3.25)
project(App2)

set(CMAKE_CXX_STANDARD 17)

add_executable(App2 main.cpp Functii/Logare.h Functii/Deschide_test.h Functii/Raspuns_intrebare.h Variabile.h Functii/Salveaza_raspunsuri.h ../App1/functions/login.h)
