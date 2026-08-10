//
// Created by S861321135 on 10/08/2026.
//

#include "Programa.h"

#include <format>
#include <iostream>
#include <filesystem>

namespace po = boost::program_options;
namespace fs = std::filesystem;

int Programa::exibirArvore(const std::string &dir) {
    if (!fs::is_directory(dir)) {
        std::cerr << std::format("{} não é um diretório", dir) << std::endl;
        return EXIT_FAILURE;
    }

    try {
        for (const auto &p: fs::recursive_directory_iterator(dir)) {
            std::cout << std::format("{}", p.path().string()) << std::endl;
        }
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int Programa::executar(int argc, char **argv) {
    po::options_description desc("Opções disponíveis");
    desc.add_options()("dir,d", po::value<std::string>(), "Diretório a partir do qual mostrar a árvore");
    desc.add_options()("ajuda,a", "Esta ajuda");

    // Processa a linha de comando e direciona para o comando correto
    try {
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
        if (vm.contains("ajuda") || vm.empty()) {
            std::ostringstream ss;
            ss << desc;
            std::cout << std::format("{}\n", ss.str());
            return EXIT_SUCCESS;
        }
        if (vm.contains("dir")) {
            const auto dir = vm["dir"].as<std::string>();
            exibirArvore(dir);
        }
    } catch (po::error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
