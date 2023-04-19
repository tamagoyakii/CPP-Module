#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: Invalid arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    RPN expression(av[1]);

    try {
        std::cout << expression.getResult() << std::endl;
    } catch (const char *e) {
        std::cout << e << std::endl;
    }

    return 0;
}
