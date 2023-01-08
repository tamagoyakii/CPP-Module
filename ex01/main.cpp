#include "Zombie.hpp"

int main() {
	Zombie* zombies = Zombie::zombieHorde(5, "horde");
	
	for (int i = 0; i < 5; i++) zombies[i].announce();
	delete[] zombies;

	std::cout << "<-----check leaks----->" << std::endl;
	system("leaks zombie");

	return 0;
}