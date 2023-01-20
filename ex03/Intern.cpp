#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& ref) {
	*this = ref;
}

Intern& Intern::operator=(const Intern& ref) {
	(void)ref;
	return *this;
}

Intern::~Intern(void) {}

AForm* Intern::makeForm(std::string name, std::string target) const {
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	try {
		for (int i = 0; i < 3; i++) {
			if (name == formNames[i]) {
				switch (i) {
					case 0:
						return new ShrubberyCreationForm(target);
					case 1:
						return new RobotomyRequestForm(target);
					case 2:
						return new PresidentialPardonForm(target);
				}
				std::cout << "Intern creates " << formNames[i] << " form" << std::endl;
			}
		}
		throw Intern::InvalidFormException();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return NULL;
}

const char* Intern::InvalidFormException::what() const throw() {
	return "exception: Invalid form";
}
