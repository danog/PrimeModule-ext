#include <iostream>
#include <string>
#include "primemodule.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "PrimeModule: extremely fast 64-bit factorization module." << std::endl
            << "Copyright (C) 2015-2021 Nikolai Kudashov, Daniil Gentili" << std::endl
            << "Licensed under GPLv2" << std::endl 
            << "https://github.com/danog/PrimeModule-ext" << std::endl
            << std::endl << "Usage: " << argv[0] << " number" << std::endl
            << std::endl << "One of the prime factors will be printed to stdout." << std::endl
            << std::endl;
        return 1;
    }
    uint64_t what;
    try {
        what = std::stoull(argv[1]);
    } catch (...) {
        std::cerr << "An invalid 64-bit integer was provided!" << std::endl;
        return 1;
    }
    uint32_t res;
    try {
        res = PrimeModule::factorize(what);
    } catch (...) {
        std::cerr << "An error occurred during factorization!" << std::endl;
        return 1;
    }
    std::cout << res << std::endl;
    return 0;
}