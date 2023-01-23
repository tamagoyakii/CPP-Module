#include "Conversion.hpp"

Conversion::Conversion(void)
	: _str(0), _isNan(0), _isInf(0), _toi(0), _toc(0), _tof(0), _tod(0) {}
	
Conversion::Conversion(char* str): _str(str), _isNan(false), _isInf(false) {
	this->_tod = strtod(str, NULL);
	this->_toi = static_cast<int>(this->_tod);
	this->_toc = static_cast<char>(this->_tod);
	this->_tof = static_cast<float>(this->_tod);

	if (this->_tod != this->_tod) this->_isNan = true;
	if (this->_tod != 0 && this->_tod * 2 == this->_tod) this->_isInf = true;
}

Conversion::Conversion(const Conversion& ref)
	: _str(ref._str), _isNan(ref._isNan), _isInf(ref._isInf), _toi(ref._toi), _toc(ref._toc), _tof(ref._tof), _tod(ref._tod) {}

Conversion& Conversion::operator=(const Conversion& ref) {
	this->_str = ref._str;
	this->_isNan = ref._isNan;
	this->_isInf = ref._isInf;
	this->_toi = ref._toi;
	this->_toc = ref._toc;
	this->_tod = ref._tod;
	this->_tof = ref._tof;
	return *this;
}

Conversion::~Conversion(void) {}

void Conversion::printChar(std::ostream& os) const {
	os << "char: ";
	if (this->_isNan || this -> _isInf) {
		os << "impossible" << std::endl;
		return;
	}
	if (std::isprint(this->_toc)) {
		os << "'" << this->_toc << "'" << std::endl;
		return;
	}
	os << "Non displayable" << std::endl;
}

void Conversion::printInt(std::ostream& os) const {
	os << "int: ";
	if (this->_isNan || this->_isInf) {
		os << "impossible" << std::endl;
		return;
	}
	if (this->_tod > std::numeric_limits<int>::max() || this->_tod < std::numeric_limits<int>::min()) {
		os << "impossible" << std::endl;
		return;
	}
	os << this->_toi << std::endl;
}

void Conversion::printFloat(std::ostream& os) const {
	os << "float: ";
	if (this->_isNan) {
		os << "nanf" << std::endl;
		return;
	}
	if (this->_isInf) {
		os << (this->_tof > 0 ? "inff" : "-inff") << std::endl;
		return;
	}
	if (this->_tod > std::numeric_limits<float>::max() || this->_tod < -std::numeric_limits<float>::max()) {
		os << "impossible" << std::endl;
		return;
	}
	os << std::fixed <<	std::setprecision(1) << this->_tof << "f" << std::endl;
}

void Conversion::printDouble(std::ostream& os) const {
	os << "double: ";
	if (this->_isNan) {
		os << "nan" << std::endl;
		return;
	}
	if (this->_isInf) {
		os << (this->_tof > 0 ? "inf" : "-inf") << std::endl;
		return;
	}
	os << std::fixed << std::setprecision(1) << this->_tod << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Conversion& ref) {
	ref.printChar(os);
  ref.printInt(os);
  ref.printFloat(os);
  ref.printDouble(os);
	return os;
}
