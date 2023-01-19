#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
	public:
		AForm(void);
		AForm(const std::string name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm& ref);
		AForm& operator=(const AForm& ref);
		virtual ~AForm(void);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		void beSigned(const Bureaucrat& ref);
		virtual void execute(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const AForm& ref);

#endif