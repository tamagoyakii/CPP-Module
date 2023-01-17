#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), _brain(new Brain("Cat")) {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(std::string idea): Animal("Cat"), _brain(new Brain(idea)) {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& ref): Animal(ref.getType()), _brain(new Brain(*ref._brain)) {
	std::cout << "Cat copy created" << std::endl;
}

Cat& Cat::operator=(const Cat& ref) {
	this->_type = ref.getType();
	*this->_brain = *ref._brain;
	std::cout << "Cat copied" << std::endl;
	return *this;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Cat is making a sound... MEOW...." << std::endl;
}

void Cat::showIdea(int i) const {
	std::cout << "Cat has "<< this->_brain->getIdea(i) << " in its brain " << i << std::endl;
}