#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fixedPointNum(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i << this->_fractionalBits);
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (1 << this->_fractionalBits)));
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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointNum = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_fixedPointNum / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_fixedPointNum >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}