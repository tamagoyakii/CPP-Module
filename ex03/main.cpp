#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern intern;
	AForm *form;

	std::cout << std::endl << "--------------------make form test--------------------" << std::endl;
	form = intern.makeForm("shrubbery creation", "Shrubbery");
	delete form;
	form = intern.makeForm("robotomy request", "Robot");
	delete form;
	form = intern.makeForm("presidential pardon", "President");
	delete form;
	form = intern.makeForm("unknown form", "Unknown");
	delete form;

	std::cout << std::endl << "------------------execute & sign test-----------------" << std::endl;
	std::cout << std::endl << "-----------------------shrubbery----------------------" << std::endl;
	Bureaucrat b1("lowest", 130);
	AForm *s1 = intern.makeForm("shrubbery creation", "b1_shrubbery");

	b1.signForm(*s1);
	b1.executeForm(*s1);

	delete s1;

	std::cout << std::endl << "------------------------robotomy----------------------" << std::endl;
	Bureaucrat b2("center", 40);
	AForm *r1 = intern.makeForm("robotomy request", "b2_robot");

	b2.signForm(*r1);
	b2.executeForm(*r1);

	delete r1;

	std::cout << std::endl << "----------------------presidential--------------------" << std::endl;
	Bureaucrat b3("highest", 1);
	AForm *p1 = intern.makeForm("presidential pardon", "b3_president");
	b3.signForm(*p1);
	b3.executeForm(*p1);

	delete p1;

	std::cout << std::endl << "-------------------------leaks------------------------" << std::endl;
	system("leaks a.out");

	return 0;
}