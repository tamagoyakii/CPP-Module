#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
		~Bureaucrat(void);

		std::string getName(void) const;
		int getGrade(void) const;

		void increaseGrade(void);
		void decreaseGrade(void);

		void signForm(Form &ref);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& ref);

#endif