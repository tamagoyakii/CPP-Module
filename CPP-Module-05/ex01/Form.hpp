#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
	public:
		Form(void);
		Form(const std::string name, const int gradeToSign, const int gradeToExec);
		Form(const Form& ref);
		Form& operator=(const Form& ref);
		~Form(void);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		void beSigned(const Bureaucrat& ref);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Form& ref);

#endif