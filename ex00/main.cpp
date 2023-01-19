#include "Bureaucrat.hpp"

int main(void) {
	std::cout << std::endl << "-------------Constructor Test-------------" << std::endl;

	try {
		Bureaucrat a("highest", 1);
		Bureaucrat c("potato", 151);
		Bureaucrat b("lowest", 150);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--------------Decrement Test--------------" << std::endl;

	Bureaucrat a("highest", 1);
	Bureaucrat b("lowest", 150);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try {
		a.decreaseGrade();
		b.decreaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl << "--------------Increment Test--------------" << std::endl;

	try {
		a.increaseGrade();
		a.increaseGrade();
		b.increaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}