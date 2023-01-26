#include "Span.hpp"

Span::Span(void): _size(0) {}

Span::Span(unsigned int n): _size(n) {}

Span::Span(const Span& ref): _vector(ref._vector), _size(ref._size) {}

Span& Span::operator=(const Span& ref) {
	this->_vector = ref._vector;
	this->_size = ref._size;
	return *this;
}

Span::~Span(void) {}

void Span::addNumber(int n) {
	if (this->_vector.size() == this->_size) throw NotEnoughSpaceException();
	_vector.push_back(n);
	std::cout << "adding " << n << " success!" << std::endl;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_vector.size() + end - begin > this->_size) throw NotEnoughSpaceException();
	this->_vector.insert(_vector.end(), begin, end);
	this->_size += end - begin;
}

long long Span::shortestSpan(void) {
	if (this->_vector.size() < 2) throw NeedMoreNumbersException();

	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());

	long long min = this->longestSpan();
	for (unsigned int i = 0; i < _vector.size() - 1; i++) {
		min = std::min(static_cast<long long>(tmp[i + 1]) - static_cast<long long>(tmp[i]), min);
	}
	return min;
}

long long Span::longestSpan(void) {
	if (this->_vector.size() < 2) throw NeedMoreNumbersException();

	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());
	return static_cast<long long>(tmp[tmp.size() - 1]) - static_cast<long long>(tmp[0]);
}

const char* Span::NotEnoughSpaceException::what() const throw() {
	return "exception: not enough space for new elements";
}

const char* Span::NeedMoreNumbersException::what() const throw() {
	return "exception: you need more elements";
}