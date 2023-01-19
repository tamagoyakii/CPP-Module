#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
		std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
		std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
	: AForm(ref), _target(ref.getTarget()) {
		std::cout << "ShrubberyCreationForm copy created" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
	AForm::operator=(ref);
	this->_target = ref.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (this->getIsSigned() == false) throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec()) throw GradeTooLowException();

	std::ofstream ofs(this->_target + "_shrubbery");
	if (!ofs.is_open()) {
		std::cout << "_shrubbery file open failed" << std::endl;
		return;
	}
	ofs << "       ,,,                      ,,,                   " << std::endl;
	ofs << "      {{{}}    ,,,             {{{}}    ,,,           " << std::endl;
	ofs << "   ,,, ~Y~    {{{}},,,      ,,, ~Y~    {{{}},,,       " << std::endl;
	ofs << "  {{}}} |/,,,  ~Y~{{}}}    {{}}} |/,,,  ~Y~{{}}}      " << std::endl;
	ofs << "   ~Y~ \\|{{}}}/\\|/ ~Y~  ,,, ~Y~ \\|{{}}}/\\|/ ~Y~  ,,,  " << std::endl;
	ofs << "   \\|/ \\|/~Y~  \\|,,,|/ {{}}}\\|/ \\|/~Y~  \\|,,,|/ {{}}} " << std::endl;
	ofs << "   \\|/ \\|/\\|/  \\{{{}}/  ~Y~ \\|/ \\|/\\|/  \\{{{}}/  ~Y~  " << std::endl;
	ofs << "   \\|/\\\\|/\\|/ \\\\|~Y~//  \\|/ \\|/\\\\|/\\|/ \\|~Y~//  \\\\|/  " << std::endl;
	ofs << "   \\|//\\|/\\|/,\\\\|/|/|// \\|/ \\|//\\|/\\|/,\\\\|/|/|// \\|/  " << std::endl;
	ofs << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;

	std::cout << "Target [ " << this->getName() << " ] has been created successfully" << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}