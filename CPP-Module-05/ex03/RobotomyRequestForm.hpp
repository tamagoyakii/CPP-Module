#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>  

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		void execute(const Bureaucrat& executor) const;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
		~RobotomyRequestForm(void);
		
		std::string getTarget(void) const;
};

#endif