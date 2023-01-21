#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>

class Conversion {
	private:
		std::string _str;
		bool _isNan;
		bool _isInf;
		int _toi;
		char _toc;
		float _tof;
		double _tod;
		Conversion(void);
	public:
		Conversion(std::string str);
		Conversion(const Conversion& ref);
		Conversion& operator=(const Conversion& ref);
		~Conversion(void);

		void printChar(std::ostream& os) const;
		void printInt(std::ostream& os) const;
		void printFloat(std::ostream& os) const;
		void printDouble(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Conversion& ref);

#endif