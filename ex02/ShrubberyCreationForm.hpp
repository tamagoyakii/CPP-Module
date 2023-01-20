#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		void execute(const Bureaucrat& executor) const;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm(void);

		std::string getTarget(void) const;
};

#endif