#include "Data.hpp"

Data::Data(void): _phrase("Hello World") {}

Data::Data(std::string phrase): _phrase(phrase) {}

Data::Data(const Data& ref): _phrase(ref._phrase) {}

Data& Data::operator=(const Data& ref) {
	this->_phrase = ref._phrase;
	return *this;
}

Data::~Data(void) {}

std::string Data::getPhrase(void) const {
	return this->_phrase;
}

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}