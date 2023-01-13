#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &ref);
		~ClapTrap();
		ClapTrap & operator=(ClapTrap const &ref);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;
		int getAttackDamage(void) const;
		int getHitPoints(void) const;
		int getEnergyPoints(void) const;
};

#endif