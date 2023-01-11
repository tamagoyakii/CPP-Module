#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	private:
		std::string _level[4];
		void (Harl::*_ptrFunc[4])(void);
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		void complain(std::string level);
};

#endif