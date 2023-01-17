#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void zoo(void) {
	// Animal* animals[10];

	// std::cout << "----------Create 10 Animals(5 Cats, 5 Dogs)----------" << std::endl;
	// for (int i = 0; i < 5; i++) animals[i] = new Dog();
	// for (int i = 5; i < 10; i++) animals[i] = new Cat();

	// animals[4]->makeSound();
	// animals[5]->makeSound();

	// animals[4] = animals[5];
	// animals[4]->makeSound();
	// animals[5]->makeSound();

	// std::cout << std::endl << "----------Delete Animals----------" << std::endl;
	// for (int i = 0; i < 10; i++) delete animals[i];

	Cat c1;
	Cat c2("Dog");

	c1.showIdea(5);
	c2.showIdea(5);

	c1 = c2;

	c1.showIdea(5);
	c2.showIdea(5);
}

int main(void) {
	zoo();
	system("leaks a.out");

	return 0;
}