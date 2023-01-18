#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), _brain(new Brain("Dog")) {
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(std::string idea): Animal("Dog"), _brain(new Brain(idea)) {
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& ref): Animal(ref.getType()), _brain(new Brain(*ref._brain)) {
	std::cout << "Dog copy created" << std::endl;
}

Dog& Dog::operator=(const Dog& ref) {
	this->_type = ref.getType();
	*this->_brain = *ref._brain;
	std::cout << "Dog copied" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Dog is making a sound... WOOF WOOF!" << std::endl;
}

void Dog::showIdea(int i) const {
	if (i < 0 || i >= 100) {
		std::cout << "out of brain!" << std::endl;
		return;
	}
	std::cout << "Dog has "<< this->_brain->getIdea(i) << " in its brain " << i << std::endl;
}

void Dog::setBrain(const Brain& ref) const {
	*this->_brain = ref;
}

Brain* Dog::getBrain(void) const {
	return this->_brain;
}