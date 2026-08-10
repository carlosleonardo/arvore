//
// Created by S861321135 on 10/08/2026.
//

#ifndef ARVORE_PROGRAMA_H
#define ARVORE_PROGRAMA_H
#include <boost/program_options.hpp>

class Programa {
public:
    std::string extrairNome(const std::string &caminho);

    int exibirArvore(const std::string &dir);

    int executar(int argc, char **argv);

private:
};


#endif //ARVORE_PROGRAMA_H
