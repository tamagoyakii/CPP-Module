#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat b1("jihyukim", 1);
	ShrubberyCreationForm s1("SForm");

	try {
		s1.beSigned(b1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		s1.execute(b1);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}