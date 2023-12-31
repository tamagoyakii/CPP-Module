#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad): _name(name), _hitPoints(hp), _energyPoints(ep), _attackDamage(ad) {
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& ref) : _name(ref._name), _hitPoints(ref._hitPoints), _energyPoints(ref._energyPoints), _attackDamage(ref._attackDamage) {
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name <<  " is already dead and can't attack." << std::endl;
		return;
	}
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name <<  " can't move." << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	if (_hitPoints <= 0) std::cout << "ClapTrap " << this->_name << " was attacked and died!" << std::endl;
	else std::cout << "ClapTrap " << this->_name << " was attacked, and got " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name <<  " is already dead and can't repair." << std::endl;
		return;
	}
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name <<  " can't move." << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs " << amount << " hit points." << std::endl;
}
