#include "Span.hpp"
#include <limits>

int main(void) {
	Span s1 = Span(5);

	std::cout << std::endl << "----------add numbers-----------" << std::endl;
	try {
		s1.addNumber(6);
		s1.addNumber(3);
		s1.addNumber(17);
		s1.addNumber(9);
		s1.addNumber(11);
		s1.addNumber(INT_MIN);
		s1.addNumber(INT_MAX);
		s1.addNumber(0);
		s1.addNumber(-2147483647);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "-----------span test------------" << std::endl;
	try {
		std::cout << "min: " << s1.shortestSpan() << std::endl;
		std::cout << "max: " << s1.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "-------add more numbers---------" << std::endl;
	Span s2 = Span(1000);
	std::vector<int> toAdd;

	srand(time(NULL));
	for (int i = 0; i < 1000; i++) toAdd.push_back(rand() % 1000);

	try {
		s2.addNumbers(toAdd.begin(), toAdd.end());
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "-----------span test------------" << std::endl;
	try {
		std::cout << "min: " << s2.shortestSpan() << std::endl;
		std::cout << "max: " << s2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}