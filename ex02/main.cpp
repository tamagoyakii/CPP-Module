#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	std::cout << std::endl << "-----------shrubbery creation test-----------" << std::endl;
	Bureaucrat b1("B1", 1);
	// Bureaucrat b1("B1", 140);
	// Bureaucrat b1("B1", 146);
	ShrubberyCreationForm s1("SForm");

	try {
		b1.signForm(s1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b1.executeForm(s1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "------------robotomy request test------------" << std::endl;
	Bureaucrat b2("B2", 1);
	// Bureaucrat b2("B2", 60);
	// Bureaucrat b2("B2", 80);
	RobotomyRequestForm r1("RForm");

	try {
		b2.signForm(r1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b2.executeForm(r1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "-----------presidential pardon test----------" << std::endl;
	Bureaucrat b3("B3", 1);
	// Bureaucrat b3("B3", 10);
	// Bureaucrat b3("B3", 30);
	PresidentialPardonForm p1("PForm");

	try {
		b3.signForm(p1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b3.executeForm(p1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "-----------------destruction-----------------" << std::endl;
	return 0;
}