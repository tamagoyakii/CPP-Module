#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap " << this->_name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref): ClapTrap(ref._name, ref._hitPoints, ref._energyPoints, ref._attackDamage) {
	std::cout << "FragTrap " << this->_name << " created." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& ref) {
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " is giving everyone a high five!" << std::endl;
}