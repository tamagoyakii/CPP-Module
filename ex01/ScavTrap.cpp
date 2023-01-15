#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap " << this->_name << " created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &ref) {
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap " << this->_name <<  " is already dead and can't attack." << std::endl;
		return;
	}
	if (this->_energyPoints <= 0) {
		std::cout << "ScavTrap " << this->_name <<  " can't move." << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}