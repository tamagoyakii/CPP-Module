#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat a("highest", 1);
		Bureaucrat c("potato", 151);
		Bureaucrat b("lowest", 150);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

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