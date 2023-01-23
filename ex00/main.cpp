#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

const char* NoOccurrenceException::what() const throw() {
	return "exception: no occurrence found";
}

int main(void) {
	std::vector<int> _v;
	std::deque<int> _d;
	std::list<int> _l;

	std::cout << std::endl << "---------put random value----------" << std::endl;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 10 + 1;
		std::cout << tmp << ", ";
		_v.push_back(tmp);
		_d.push_back(tmp);
		_l.push_back(tmp);
	}
	std::cout << std::endl;

	std::cout << std::endl << "--------------vector---------------" << std::endl;
	try {
		int tmp = rand() % 10 + 1;
		std::cout << "looking for " << tmp << "..." << std::endl;
		std::cout << ">> " << *(easyfind(_v, tmp)) << " found!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "--------------deque---------------" << std::endl;
	try {
		int tmp = rand() % 10 + 1;
		std::cout << "looking for " << tmp << "..." << std::endl;
		std::cout << ">> " << *(easyfind(_d, tmp)) << " found!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---------------list---------------" << std::endl;
	try {
		int tmp = rand() % 10 + 1;
		std::cout << "looking for " << tmp << "..." << std::endl;
		std::cout << ">> " << *(easyfind(_l, tmp)) << " found!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}