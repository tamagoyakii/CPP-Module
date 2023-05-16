#include "PmergeMe.hpp"

#include <iomanip>
#include <iostream>

bool isValidNumber(const char *end, long number) {
    if (*end != '\0')
        return false;
    if (number < INT_MIN || number > INT_MAX)
        return false;
    if (number <= 0)
        return false;
    return true;
}

template <typename T> void addNumbers(int ac, char *av[], T &container) {
    for (int i = 1; i < ac; i++) {
        char *end;
        long number = strtol(av[i], &end, 10);

        if (isValidNumber(end, number))
            container.push_back(number);
        else {
            std::cout << "Error: invalid element" << std::endl;
            exit(1);
        }
    }
}

template <typename T> void printContainer(std::string str, T container) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    std::cout << str;
    for (; it != ite; it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int ac, char *av[]) {
    if (ac < 3) {
        std::cout << "Error: need more arguments" << std::endl;
        exit(EXIT_FAILURE);
    } else if (ac > 3001) {
        std::cout << "Error: too many arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    PmergeMe p;
    std::vector<int> before;
    std::vector<int> vectorSort;
    std::list<int> listSort;

    addNumbers(ac, av, before);
    addNumbers(ac, av, vectorSort);
    addNumbers(ac, av, listSort);

    clock_t vectorStart = clock();
    p.mergeInsertSort(vectorSort, 0, vectorSort.size() - 1);
    clock_t vectorEnd = clock();

    clock_t listStart = clock();
    p.mergeInsertSort(listSort, listSort.begin(), listSort.end());
    clock_t listEnd = clock();

    double vectorTime = static_cast<double>(vectorEnd - vectorStart) / 1000;
    double listTime = static_cast<double>(listEnd - listStart) / 1000;

    printContainer("Before: ", before);
    printContainer("After: ", vectorSort);

    std::cout << "Time to process a range of " << vectorSort.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << vectorTime
              << " us" << std::endl;
    std::cout << "Time to process a range of " << listSort.size()
              << " elements with std::list : " << std::fixed << std::setprecision(5) << listTime
              << " us" << std::endl;

    return 0;
}