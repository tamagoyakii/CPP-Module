#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& ref): Animal(ref.getType()) {
	std::cout << "Cat copy created" << std::endl;
}

Cat& Cat::operator=(const Cat& ref) {
	this->_type = ref.getType();
	std::cout << "Cat copied" << std::endl;
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Cat is making a sound... MEOW...." << std::endl;
}