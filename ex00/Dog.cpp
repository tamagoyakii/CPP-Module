#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& ref): Animal(ref.getType()) {
	std::cout << "Dog copy created" << std::endl;
}

Dog& Dog::operator=(const Dog& ref) {
	this->_type = ref.getType();
	std::cout << "Dog copied" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Dog is making a sound... WOOF WOOF!" << std::endl;
}