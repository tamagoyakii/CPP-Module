#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongLion") {
	std::cout << "WrongAnimal " << this->_type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << "WrongAnimal " << this->_type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref): _type(ref.getType()) {
	std::cout << "WrongAnimal " << this->_type << " copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref) {
	this->_type = ref.getType();
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal " << this->_type << " destroyed" << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal is making a sound... shh....." << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->_type;
}