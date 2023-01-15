#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void zoo(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	WrongAnimal* wrong = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();
	wrong->makeSound();
	wrongCat->makeSound();

	delete wrong;
	delete wrongCat;
}

int main(void) {
	zoo();
	system("leaks a.out");

	return 0;
}