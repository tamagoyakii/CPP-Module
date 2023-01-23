#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base* generate(void) {
	Base* bPtr;

	switch (rand() % 3) {
		case 0:
			bPtr = new A();
			std::cout << "class A created" << std::endl;
			break;
		case 1:
			bPtr = new B();
			std::cout << "class B created" << std::endl;
			break;
		case 2:
			bPtr = new C();
			std::cout << "class C created" << std::endl;
			break;
	}
	return bPtr;
}

void identify(Base* p) {
	std::cout << "ptr: Base ptr is actually pointing at ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	std::cout << "ref: Base ptr is actually pointing at ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {}
}

int main(void) {
	srand(time(NULL));
	Base* b1 = generate();
	identify(b1);
	identify(*b1);

	Base* b2 = generate();
	identify(b2);
	identify(*b2);
	
	Base* b3 = generate();
	identify(b3);
	identify(*b3);

	delete b1;
	delete b2;
	delete b3;

	system("leaks a.out");
	return 0;
}