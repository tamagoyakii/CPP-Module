#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;
	public:
		Dog(void);
		Dog(std::string idea);
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		~Dog(void);

		void makeSound(void) const;
		void showIdea(int i) const;
		void setBrain(const Brain& ref) const;
		Brain* getBrain(void) const;
};

#endif