#include "Data.hpp"

int main(void) {

	Data* dPtr = new Data("NO MORE CPP!");
	uintptr_t uintptr;

	std::cout << std::endl << "--------------------Check Data--------------------"<< std::endl;
	std::cout << "dPtr        : " << dPtr << std::endl;
	std::cout << "dPtr phrase : " << dPtr->getPhrase() << std::endl;
	std::cout << std::endl << "--------------------Serialize---------------------"<< std::endl;
	uintptr = serialize(dPtr);
	std::cout << "uintptr     : " << uintptr << std::endl;
	std::cout << std::endl << "--------------------Deserialize-------------------"<< std::endl;
	std::cout << "deserialize : " << deserialize(uintptr) << std::endl;
	std::cout << "deserialize : " << deserialize(uintptr)->getPhrase() << std::endl;

	delete dPtr;

	return 0;
}