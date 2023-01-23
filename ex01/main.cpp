#include "Span.hpp"

int main(void) {
	Span sp = Span(5);

	std::cout << std::endl << "----------add numbers-----------" << std::endl;
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(22);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "-----------span test------------" << std::endl;
	try {
		std::cout << "max: " << sp.shortestSpan() << std::endl;
		std::cout << "min: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}