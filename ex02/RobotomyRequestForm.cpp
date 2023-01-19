#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("Default") {
		std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
		std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
	: AForm(ref), _target(ref.getTarget()) {
		std::cout << "RobotomyRequestForm copy created" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
	AForm::operator=(ref);
	this->_target = ref.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (this->getIsSigned() == false) throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec()) throw GradeTooLowException();

	std::cout << "...Drrrrrrriiiillllllllliiiingggg.....nnnnnoissesss..." << std::endl;
	if (rand() % 2) std::cout << "Target [ " << this->_target << " ] has been robotomized successfully" << std::endl;
	else std::cout << "robotomy failed!" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}