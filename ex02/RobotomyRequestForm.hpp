#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
		~RobotomyRequestForm(void);
		
		void execute(const Bureaucrat& executor) const;
		std::string getTarget(void) const;
};

#endif