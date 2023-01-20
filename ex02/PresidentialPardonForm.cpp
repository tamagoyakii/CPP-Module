#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), _target("Default") {
		std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
		std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
	: AForm(ref), _target(ref.getTarget()) {
		std::cout << "PresidentialPardonForm copy created" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
	AForm::operator=(ref);
	this->_target = ref.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (this->getIsSigned() == false) throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec()) throw GradeTooLowException();
	std::cout << "Target [ " << this->_target << " ] has been pardoned by Zaphod Beeblebro" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const {
	return this->_target;
}