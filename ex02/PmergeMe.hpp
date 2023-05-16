#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>

class PmergeMe {
  private:
    void insertSort(std::vector<int> &numbers, int left, int right);
    void insertSort(std::list<int>::iterator left, std::list<int>::iterator right);
    void mergeSort(std::vector<int> &numbers, int left, int mid, int right);
    void mergeSort(std::list<int>::iterator left, std::list<int>::iterator mid,
                   std::list<int>::iterator right);

  public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &ref);
    PmergeMe &operator=(const PmergeMe &ref);

    void mergeInsertSort(std::vector<int> &numbers, int left, int right);
    void mergeInsertSort(std::list<int> &numbers, std::list<int>::iterator left,
                         std::list<int>::iterator right);
};

#endif