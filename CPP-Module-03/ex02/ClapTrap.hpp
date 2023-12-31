#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int ep, int ad);
		ClapTrap(const ClapTrap& ref);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& ref);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif