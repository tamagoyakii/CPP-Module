#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    BitcoinExchange a(av[1]);
    a.execute();
    return 0;
}