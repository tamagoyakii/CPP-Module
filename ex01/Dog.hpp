#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;
	public:
		Dog(void);
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		~Dog(void);

		void makeSound(void) const;
		void showIdea(int i) const;
};

#endif