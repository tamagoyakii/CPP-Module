#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat b1("highest", 1);
	Bureaucrat b2("center", 50);
	Bureaucrat b3("lowest", 150);
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	std::cout << std::endl << "----------------form test----------------" << std::endl;

	try {
		// Form f0("unavailable_form", 0, 0);
		Form f1("secret_form", 1, 1);
		Form f2("normal_form", 150, 150);
		Form f3("unavailable_form", 151, 151);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "----------------sign test----------------" << std::endl;

	Form f1("secret_form", 1, 1);
	Form f2("important_form", 50, 50);
	Form f3("normal_form", 150, 150);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	try {
		b1.signForm(f3);
		b1.signForm(f2);
		b1.signForm(f1);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b2.signForm(f3);
		b2.signForm(f2);
		b2.signForm(f1);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b3.signForm(f3);
		b3.signForm(f2);
		b3.signForm(f1);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}