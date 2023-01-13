#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixedPointNum;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &ref);
		Fixed& operator=(const Fixed &ref);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		// The 6 comparison operators
		bool operator>(const Fixed& f) const;
		bool operator<(const Fixed& f) const;
		bool operator>=(const Fixed& f) const;
		bool operator<=(const Fixed& f) const;
		bool operator==(const Fixed& f) const;
		bool operator!=(const Fixed& f) const;
		// The 4 arithmetic operators
		Fixed	operator+(const Fixed& f);
		Fixed	operator-(const Fixed& f);
		Fixed	operator*(const Fixed& f);
		Fixed	operator/(const Fixed& f);
		// The 4 increment/decrement operators 
		Fixed& operator++();
		Fixed& operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		// four public overloaded member functions
		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
};

std::ostream& operator<<(std::ostream& out, const Fixed &ref);

#endif