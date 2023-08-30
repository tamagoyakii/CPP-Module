#include "Array.hpp"

void makeArray(void) {
	Array<int> _int(10);
	int _cmp[10];

	std::cout << std::endl << "---------put random value----------" << std::endl;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		const int x = rand() % 10 + 1;
		_int[i] = x;
		_cmp[i] = x;
		std::cout << i << ": " << x << std::endl;
	}

	std::cout << std::endl << "--------check random value---------" << std::endl;
	for (int i = 0; i < 10; i++) {
		if (_int[i] == _cmp[i]) std::cout << i << ": OK!" << std::endl;
		else std::cout << "IT'S NOT A SAME VALUE!!!" << std::endl;
	}

	std::cout << std::endl << "----------operator[] test----------" << std::endl;
	for (int i = -2; i < 12; i++) {
		try {
			std::cout << i << ": " << _int[i] << std::endl;
		} catch (const std::exception& e) {
			std::cout << i << ": " << e.what() << std::endl;
		}
	}
}

int main(void) {
	makeArray();
	std::cout << std::endl << "---------------leaks---------------" << std::endl;
	system("leaks a.out");

	return 0;
}