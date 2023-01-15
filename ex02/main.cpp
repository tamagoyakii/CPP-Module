#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap a("A");
	FragTrap b("B");

	a.attack("B");
	b.attack("A");

	b.takeDamage(20);
	a.takeDamage(20);
	b.beRepaired(10);

	a.guardGate();
	b.highFivesGuys();

	return 0;
}