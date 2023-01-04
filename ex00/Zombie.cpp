#include "Zombie.hpp"

Zombie::Zombie(): _name("DEFAULT") {}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << this->_name << " the zombie is dead..." << std::endl;
	return;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
