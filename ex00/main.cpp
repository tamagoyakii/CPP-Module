#include "Zombie.hpp"

void makeHeapZombie() {
	Zombie *heap_zombie = newZombie("HEAP");
	heap_zombie->announce();
	delete heap_zombie;
}

int main() {
	Zombie default_zombie;
	default_zombie.announce();

	makeHeapZombie();

	randomChump("Voodoo");

	std::cout << "<-----check leaks----->" << std::endl;
	system("leaks zombie");

	return 0;
}