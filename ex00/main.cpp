#include "ClapTrap.hpp"

int main() {
	ClapTrap a("A");
	ClapTrap b("B");
	ClapTrap c("C");

	a.attack("B");

	for (int i = 0; i < 10; i ++) b.attack("C");

	b.attack("C");

	c.takeDamage(2);
	c.beRepaired(2);

	for (int i = 0; i < 5; i++) c.takeDamage(2);

	c.beRepaired(10);
	c.attack("A");
	
	return 0;
}