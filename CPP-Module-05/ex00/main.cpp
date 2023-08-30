#include "Bureaucrat.hpp"

int main(void) {
	std::cout << std::endl << "-------------Constructor Test-------------" << std::endl;

	try {
		Bureaucrat b1("highest", 1);
		Bureaucrat b2("potato", 151);
		Bureaucrat b3("lowest", 150);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--------------Decrement Test--------------" << std::endl;

	Bureaucrat b1("highest", 1);
	Bureaucrat b2("lowest", 150);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	try {
		b1.decreaseGrade();
		b2.decreaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	std::cout << std::endl << "--------------Increment Test--------------" << std::endl;

	try {
		b1.increaseGrade();
		b1.increaseGrade();
		b2.increaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	return 0;
}