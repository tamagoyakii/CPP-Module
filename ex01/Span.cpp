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
	if (this->_vector.size() == this->_size) throw FullElementsException();
	_vector.push_back(n);
}

int Span::shortestSpan(void) {
	if (this->_vector.size() < 2) throw NeedMoreNumbersException();

	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());

	int min = this->longestSpan();
	for (unsigned int i = 0; i < _vector.size() - 1; i++) {
		min = std::min(tmp[i + 1] - tmp[i], min);
	}

	return min;
}

int Span::longestSpan(void) {
	if (this->_vector.size() < 2) throw NeedMoreNumbersException();

	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());

	return tmp[tmp.size() - 1] - tmp[0];
}

const char* Span::FullElementsException::what() const throw() {
	return "exception: span is already full";
}

const char* Span::NeedMoreNumbersException::what() const throw() {
	return "exception: you need more elements";
}