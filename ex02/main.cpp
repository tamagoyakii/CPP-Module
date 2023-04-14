#include "PmergeMe.hpp"

bool isPositiveInt(const std::string &s) {
    std::istringstream iss(s);
    int num;

    iss >> std::noskipws >> num;
    if (!iss.eof() || iss.fail())
        return false;

    return num <= std::numeric_limits<int>::max() && num > 0;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error: need more arguments" << std::endl;
        exit(EXIT_FAILURE);
    } else if (ac > 3001) {
        std::cout << "Error: Too many arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    PmergeMe m;

    for (int i = 1; i < ac; i++) {
        if (isPositiveInt(av[i])) {
            std::istringstream iss(av[i]);
            int num;

            iss >> num;
            m.addNumber(num);
        } else {
            std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    m.setSize(ac - 1);
    m.execute();
    return 0;
}