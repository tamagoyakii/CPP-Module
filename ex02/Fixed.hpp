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

		//6 comparison operators
		bool	operator>(const Fixed& f);
		bool	operator<(const Fixed& f);
		bool	operator>=(const Fixed& f);
		bool	operator<=(const Fixed& f);
		bool	operator==(const Fixed& f);
		bool	operator!=(const Fixed& f);

		//4 arithmetic operators
		Fixed	operator+(const Fixed& f);
		Fixed	operator-(const Fixed& f);
		Fixed	operator*(const Fixed& f);
		Fixed	operator/(const Fixed& f);

		// 4 increment/decrement operators 
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
	
		//4 public overloaded member functions
		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		const static Fixed& min(const Fixed& lhs, const Fixed& rhs);
		const static Fixed& max(const Fixed& lhs, const Fixed& rhs);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &ref);

#endif