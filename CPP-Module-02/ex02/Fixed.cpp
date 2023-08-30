#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fixedPointNum(0){}

Fixed::Fixed(const int i) {
	setRawBits(i << this->_fractionalBits);
}

Fixed::Fixed(const float f) {
	setRawBits(roundf(f * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed &ref) {
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed &ref) {
	setRawBits(ref.getRawBits());
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointNum = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_fixedPointNum / (1 << this->_fractionalBits);
}

bool Fixed::operator>(const Fixed& f) const {
	return this->toFloat() > f.toFloat();
}

bool Fixed::operator<(const Fixed& f) const {
	return this->toFloat() < f.toFloat();
}

bool Fixed::operator>=(const Fixed& f) const {
	return this->toFloat() >= f.toFloat();
}

bool Fixed::operator<=(const Fixed& f) const {
	return this->toFloat() <= f.toFloat();
}

bool Fixed::operator==(const Fixed& f) const {
	return this->toFloat() == f.toFloat();
}

bool Fixed::operator!=(const Fixed& f) const {
	return this->toFloat() != f.toFloat();
}

Fixed	Fixed::operator+(const Fixed& f) {
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed& f) {
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed& f) {
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed& f) {
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++() {
	this->_fixedPointNum++;
	return *this;
}

Fixed& Fixed::operator--() {
	this->_fixedPointNum--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed res(*this);

	this->_fixedPointNum++;
	return res;
}

Fixed	Fixed::operator--(int) {
	Fixed res(*this);

	this->_fixedPointNum--;
	return res;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}