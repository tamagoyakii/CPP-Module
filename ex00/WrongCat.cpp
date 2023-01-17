#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref): WrongAnimal(ref.getType()) {
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& ref) {
	this->_type = ref.getType();
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat is making a sound... WOOF WOOF!!!" << std::endl;
}