#include "ScavTrap.hpp"

int main() {
	ScavTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.attack("A");

	b.takeDamage(20);
	a.takeDamage(20);
	b.beRepaired(10);

	a.guardGate();
	b.guardGate();

	return 0;
}