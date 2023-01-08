#include "Zombie.hpp"

Zombie::Zombie(): _name("STACK") {}

Zombie::Zombie(std::string name): _name(name){}

Zombie::~Zombie() {
	std::cout << _name << " the zombie is dead..." << std::endl;
	return;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
