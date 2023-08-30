#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixedPointNum;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &ref);
		Fixed& operator=(const Fixed &ref);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif