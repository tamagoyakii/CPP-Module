#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: invalid arguments." << std::endl;
        exit(EXIT_FAILURE);
    }

    BitcoinExchange a(av[1], "data.csv");

    a.execute();

    return 0;
}
