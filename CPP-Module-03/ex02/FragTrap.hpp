#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& ref);
		FragTrap& operator=(const FragTrap& ref);
		~FragTrap(void);
		void highFivesGuys(void);
};

#endif