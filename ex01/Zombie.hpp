#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string _name;
	public:
		~Zombie();
		static Zombie* zombieHorde(int N, std::string name);
		void announce();
};

#endif