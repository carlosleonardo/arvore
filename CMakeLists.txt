cmake_minimum_required(VERSION 4.3)
project(arvore)

set(CMAKE_CXX_STANDARD 20)

add_executable(arvore main.cpp terminal.h terminal.cpp
        Programa.cpp
        Programa.h)
find_package(Boost REQUIRED COMPONENTS program_options)
target_link_libraries(arvore PRIVATE Boost::program_options)