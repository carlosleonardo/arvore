#include <iostream>

#include "Programa.h"
#include "terminal.h"

int main(int argc, char **argv) {
    terminal_initialize();
    std::cout << "Visão em árvore dos diretórios!" << std::endl;
    Programa programa;
    return programa.executar(argc, argv);
}
