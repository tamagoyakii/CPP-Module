#include "Zombie.hpp"

void makeZombieHorde() {
	Zombie* zombies = zombieHorde(5, "horde");

	for (int i = 0; i < 5; i++) zombies[i].announce();
	delete[] zombies;
}

int main() {
	makeZombieHorde();

	std::cout << "<-----check leaks----->" << std::endl;
	system("leaks zombie");

	return 0;
}