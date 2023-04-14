#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

class PmergeMe {
  private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    int _size;

    template <typename T> void printContainer(std::string str, T res) {
        typename T::iterator it = res.begin();
        typename T::iterator ite = res.end();

        std::cout << str;
        for (; it != ite; it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    void insertSort(std::vector<int> &vec);
    void mergeSort(std::deque<int> &deq, int left, int right);
    void merge(std::deque<int> &deq, int left, int mid, int right);

  public:
    PmergeMe();
    PmergeMe(const PmergeMe &ref);
    ~PmergeMe();

    void addNumber(int num);
    void setSize(const int num);
    void execute();

    std::vector<int> getVector() const;
    std::deque<int> getDeque() const;
    int getSize() const;

    PmergeMe &operator=(const PmergeMe &ref);
};

#endif