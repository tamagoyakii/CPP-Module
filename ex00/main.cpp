#include "ClapTrap.hpp"

int main() {
	ClapTrap a("jihyukim");
	ClapTrap b("him");
	ClapTrap c("her");

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());

	for (int i = 0; i < 10; i ++) {
		b.attack(c.getName());
		c.takeDamage(b.getAttackDamage());
	}

	b.attack(c.getName());

	for (int i = 0; i < 5; i++) {
		c.takeDamage(2);
	}

	c.beRepaired(10);
	c.attack(a.getName());
	
	return 0;
}