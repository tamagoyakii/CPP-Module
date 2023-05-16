#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref) { *this = ref; }

PmergeMe &PmergeMe::operator=(const PmergeMe &ref) {
    (void)ref;
    return *this;
}

void PmergeMe::insertSort(std::vector<int> &numbers, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = numbers[i];
        int j = i;

        while (--j >= left && numbers[j] > key)
            numbers[j + 1] = numbers[j];
        numbers[j + 1] = key;
    }
}

#include <iostream>
void PmergeMe::insertSort(std::list<int>::iterator left, std::list<int>::iterator right) {
    for (std::list<int>::iterator i = left; i != right; ++i) {
        int key = *i;
        std::list<int>::iterator j = i;

        while (j != left && *(--j) > key) {
            std::list<int>::iterator tmp = j;
            ++tmp;
            *tmp = *j;
            *j = key;
        }
    }
}

void PmergeMe::mergeSort(std::vector<int> &numbers, int left, int mid, int right) {
    std::vector<int> tmp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (numbers[i] <= numbers[j])
            tmp.push_back(numbers[i++]);
        else
            tmp.push_back(numbers[j++]);
    }

    while (i <= mid)
        tmp.push_back(numbers[i++]);

    while (j <= right)
        tmp.push_back(numbers[j++]);

    for (int k = left; k <= right; k++)
        numbers[k] = tmp[k - left];
}

void PmergeMe::mergeSort(std::list<int>::iterator left, std::list<int>::iterator mid,
                         std::list<int>::iterator right) {
    std::list<int> tmp;
    std::list<int>::iterator it1 = left;
    std::list<int>::iterator it2 = mid;

    while (it1 != mid && it2 != right) {
        if (*it1 < *it2)
            tmp.push_back(*(it1++));
        else
            tmp.push_back(*(it2++));
    }

    while (it1 != mid)
        tmp.push_back(*(it1++));

    while (it2 != right)
        tmp.push_back(*(it2++));

    std::list<int>::iterator it_out = left;
    std::list<int>::iterator it_tmp = tmp.begin();

    while (it_out != right)
        *(it_out++) = *(it_tmp++);
}

void PmergeMe::mergeInsertSort(std::vector<int> &numbers, int left, int right) {
    if (right - left + 1 <= 15)
        insertSort(numbers, left, right);
    else {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeInsertSort(numbers, left, mid);
            mergeInsertSort(numbers, mid + 1, right);
            mergeSort(numbers, left, mid, right);
        }
    }
}

void PmergeMe::mergeInsertSort(std::list<int> &numbers, std::list<int>::iterator left,
                               std::list<int>::iterator right) {
    if (std::distance(left, right) + 1 <= 15)
        insertSort(left, right);
    else {
        std::list<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        mergeInsertSort(numbers, left, mid);
        mergeInsertSort(numbers, mid, right);
        mergeSort(left, mid, right);
    }
}