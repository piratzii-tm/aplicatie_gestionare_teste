cmake_minimum_required(VERSION 3.25)
project(App1)

set(CMAKE_CXX_STANDARD 14)

add_executable(App1
        App1.cpp functions/login.h functions/fileExists.h functions/logout.h functions/vizualizareProfil.h)
