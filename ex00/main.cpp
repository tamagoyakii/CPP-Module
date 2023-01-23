#include "Conversion.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "wrong parameters" << std::endl;
		return 0;
	}
	std::cout << Conversion(av[1]) << std::endl;
	return 0;
}