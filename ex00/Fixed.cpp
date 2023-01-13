#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointNum(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed &ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(ref.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointNum = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}