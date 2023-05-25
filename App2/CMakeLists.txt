cmake_minimum_required(VERSION 3.25)
project(App2)

set(CMAKE_CXX_STANDARD 17)

add_executable(App2 main.cpp ../Share/Clase/Student.h ../Share/Clase/Student.cpp Functii/Logare.h)
