#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("jihyukim"), _grade(150) {
	std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (this->_grade < 1) throw GradeTooHighException();
	if (this->_grade > 150) throw GradeTooLowException();
	std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref): _name(ref.getName()), _grade(ref.getGrade()) {
	std::cout << "Bureaucrat " << this->_name << " copy created" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	this->_grade = ref.getGrade();
	std::cout << "Bureaucrat " << this->_name << " copied bureaucrat " << ref.getName() << std::endl;
	return *this;
};

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

std::string Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::increaseGrade(void) {
	std::cout << "Upgrading " << this->_name << "..." << std::endl;
	if (this->_grade <= 1) throw GradeTooHighException();
	--this->_grade;
	std::cout << "...SUCCESS!" << std::endl;
}

void Bureaucrat::decreaseGrade(void) {
	std::cout << "Downgrading " << this->_name << "..." << std::endl;
	if (this->_grade >= 150) throw GradeTooLowException();
	++this->_grade;
	std::cout << "...SUCCESS!" << std::endl;
}

void Bureaucrat::signForm(AForm &ref) {
	std::cout << "Bureaucrat [ " << this->_name << " ] is trying to sign [ " << ref.getName() << " ]..." << std::endl;
	try {
		ref.beSigned(*this);
	} catch (const std::exception& e) {
		std::cout << "Bureaucrat [ " << this->_name << " ] couldn’t sign [ " << ref.getName() << " ] because of its " << e.what() << std::endl;
		return;
	}
		std::cout << "Bureaucrat [ "<< this->_name << " ] signed [ " << ref.getName() << " ]" << std::endl;
}

void Bureaucrat::executeForm(const AForm& ref) {
	std::cout << "Bureaucrat [ " << this->_name << " ] is trying to execute [ " << ref.getName() << " ]..." << std::endl;
	try {
		ref.execute(*this);
	} catch (const std::exception& e) {
		std::cout << "Bureaucrat [ " << this->_name <<  " ] couldn’t execute [ " << ref.getName() << " ] because of its " << e.what() << std::endl;
		return;
	}
	std::cout << "Bureaucrat [ "<< this->_name << " ] executed [ " << ref.getName() << " ]" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "...Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "...Grade too low!";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& ref) {
	return out << "[ Bureaucrat | " << ref.getName() <<  " ] grade: " << ref.getGrade();
}