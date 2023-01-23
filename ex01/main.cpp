#include "iter.hpp"

void print(const int& a) {
	std::cout << a << std::endl;
}

int main(void) {
	int *arr = new int[6];

	for(int i = 0; i < 6; i++) arr[i] = i;
	iter(arr, 6, print);

	delete[] arr;
	
	return 0;
}