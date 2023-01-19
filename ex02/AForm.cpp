#include "AForm.hpp"

AForm::AForm(void)
	: _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "AForm " << this->_name << " created" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1) throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150) throw AForm::GradeTooLowException();
	std::cout << "AForm " << this->_name << " created" << std::endl;
}

AForm::AForm(const AForm& ref)
	: _name(ref.getName()), _isSigned(false), _gradeToSign(ref.getGradeToSign()), _gradeToExec(ref.getGradeToExec()) {
	std::cout << "AForm " << this->_name << " copy created" << std::endl;
}

AForm& AForm::operator=(const AForm& ref) {
	this->_isSigned = ref.getIsSigned();
	std::cout << "AForm " << this->_name << " copied form" << ref.getName() << std::endl;
	return *this;
}

AForm::~AForm(void) {
	std::cout << "AForm " << this->_name << " destroyed" << std::endl;
}

std::string AForm::getName(void) const {
	return this->_name;
}

bool AForm::getIsSigned(void) const {
	return this->_isSigned;
}

int AForm::getGradeToSign(void) const {
	return this->_gradeToSign;
}

int AForm::getGradeToExec(void) const {
	return this->_gradeToExec;
}

void AForm::beSigned(const Bureaucrat& ref) {
	if (ref.getGrade() > this->_gradeToSign) throw AForm::GradeTooLowException();
	if (this->_isSigned) throw AForm::FormAlreadySignedException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "exception: Your grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "exception: Your grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "exception: This form is not signed!";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "exception: This form is already signed";
}

std::ostream& operator<<(std::ostream &out, const AForm& ref) {
	return out << "[ AForm | " << ref.getName() <<  " ] isSigned: " << ref.getIsSigned() << ", gradeToSign: " << ref.getGradeToSign() << ", gradeToExec: " << ref.getGradeToExec();
}