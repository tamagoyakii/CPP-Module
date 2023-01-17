#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void zoo(void) {
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();

	// delete meta;
	delete i;
	delete j;

	// const WrongCat* alpha = new WrongCat();
	// const WrongAnimal* a = alpha;
	// alpha->makeSound();
	// a->makeSound();

	// delete alpha;

	// const WrongAnimal* beta = new WrongAnimal();
	// const WrongAnimal* b1 = new WrongCat();
	// const WrongCat* b2 = new WrongCat();
	// beta->makeSound();
	// b1->makeSound();
	// b2->makeSound();

	// delete beta;
	// delete b1;
	// delete b2;
}

int main(void) {
	zoo();
	system("leaks a.out");

	return 0;
}