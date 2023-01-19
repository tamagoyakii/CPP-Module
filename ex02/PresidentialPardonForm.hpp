#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
		~PresidentialPardonForm(void);
		
		void execute(const Bureaucrat& executor) const;
		std::string getTarget(void) const;
};

#endif