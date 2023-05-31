cmake_minimum_required(VERSION 3.25)
project(App1)

set(CMAKE_CXX_STANDARD 14)

add_executable(App1
        App1.cpp
        functions/login.h
        functions/helpers/fileExists.h
        functions/logout.h
        functions/vizualizareProfil.h classes/Exercitiu.h classes/Exercitiu.cpp classes/Test.h functions/creareTest.h classes/Test.cpp functions/helpers/verifyCreateSession.h functions/adugareIntrebare.h classes/Professor.h classes/Professor.cpp functions/helpers/getTest.h)

