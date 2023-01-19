#include "Form.hpp"

Form::Form(void)
	: _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1) throw GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150) throw GradeTooLowException();
	std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::Form(const Form& ref)
	: _name(ref.getName()), _isSigned(false), _gradeToSign(ref.getGradeToSign()), _gradeToExec(ref.getGradeToExec()) {
	std::cout << "Form " << this->_name << " copy created" << std::endl;
}

Form& Form::operator=(const Form& ref) {
	this->_isSigned = ref.getIsSigned();
	std::cout << "Form " << this->_name << " copied form" << ref.getName() << std::endl;
	return *this;
}

Form::~Form(void) {
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

std::string Form::getName(void) const {
	return this->_name;
}

bool Form::getIsSigned(void) const {
	return this->_isSigned;
}

int Form::getGradeToSign(void) const {
	return this->_gradeToSign;
}

int Form::getGradeToExec(void) const {
	return this->_gradeToExec;
}

void Form::beSigned(const Bureaucrat& ref) {
	if (ref.getGrade() > this->_gradeToSign) throw GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "high grade!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "low grade!";
}

std::ostream& operator<<(std::ostream &out, const Form& ref) {
	return out << "[ Form | " << ref.getName() <<  " ] isSigned: " << ref.getIsSigned() << ", gradeToSign: " << ref.getGradeToSign() << ", gradeToExec: " << ref.getGradeToExec();
}