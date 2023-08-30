#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern& ref);
		Intern& operator=(const Intern& ref);
		~Intern(void);

		AForm* makeForm(std::string name, std::string target) const;

		class InvalidFormException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif