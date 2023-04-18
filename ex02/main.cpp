#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error: need more arguments" << std::endl;
        exit(EXIT_FAILURE);
    } else if (ac > 3001) {
        std::cout << "Error: too many arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    PmergeMe m;

    for (int i = 1; i < ac; i++) {
        std::istringstream iss(av[i]);
        int num;

        iss >> num;
        if (!iss.eof() || iss.fail() || num <= 0 || num > std::numeric_limits<int>::max()) {
            std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
        m.addNumber(num);
    }
    m.setSize(ac - 1);
    m.execute();
    return 0;
}