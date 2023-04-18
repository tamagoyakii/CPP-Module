#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref)
    : _vec(ref.getVector()), _deq(ref.getDeque()), _size(ref.getSize()) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::insertSort(std::vector<int> &vec) {
    int n = vec.size();

    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i;

        while (--j >= 0 && vec[j] > key)
            vec[j + 1] = vec[j];
        vec[j + 1] = key;
    }
}

void PmergeMe::merge(std::deque<int> &deq, int left, int mid, int right) {
    std::deque<int> leftDeq;
    std::deque<int> rightDeq;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    for (int i = 0; i < n1; ++i)
        leftDeq.push_back(deq[left + i]);
    for (int j = 0; j < n2; ++j)
        rightDeq.push_back(deq[mid + 1 + j]);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftDeq[i] <= rightDeq[j])
            deq[k] = leftDeq[i++];
        else
            deq[k] = rightDeq[j++];
        ++k;
    }
    while (i < n1)
        deq[k++] = leftDeq[i++];
    while (j < n2)
        deq[k++] = rightDeq[j++];
}

void PmergeMe::mergeSort(std::deque<int> &deq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(deq, left, mid);
        mergeSort(deq, mid + 1, right);
        merge(deq, left, mid, right);
    }
}

void PmergeMe::addNumber(int num) {
    _vec.push_back(num);
    _deq.push_back(num);
}

void PmergeMe::setSize(const int num) { _size = num; }

void PmergeMe::execute() {
    clock_t start;
    double insertTime;
    double mergeTime;

    std::vector<int> vec = _vec;
    std::deque<int> deq = _deq;

    start = clock();
    insertSort(vec);
    insertTime = static_cast<double>(clock() - start) / 1000;

    start = clock();
    mergeSort(deq, 0, _size - 1);
    mergeTime = static_cast<double>(clock() - start) / 1000;

    printContainer("Before: ", _vec);
    // printContainer("Before: ", _deq);
    printContainer("After: ", vec);
    // printContainer("After: ", deq);

    std::cout << "Time to process a range of " << _size
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << insertTime
              << " us" << std::endl;
    std::cout << "Time to process a range of " << _size
              << " elements with std::deque : " << std::fixed << std::setprecision(5) << mergeTime
              << " us" << std::endl;
}

std::vector<int> PmergeMe::getVector() const { return _vec; }

std::deque<int> PmergeMe::getDeque() const { return _deq; }

int PmergeMe::getSize() const { return _size; }

PmergeMe &PmergeMe::operator=(const PmergeMe &ref) {
    if (this != &ref) {
        this->_vec = ref.getVector();
        this->_deq = ref.getDeque();
        this->_size = ref.getSize();
    }
    return *this;
}
