#include "iter.hpp"

int main(void) {
	int arr[10];
	char brr[10];

	for(int i = 0; i < 10; i++) {
		arr[i] = i;
		brr[i] = i + 'a';
	}
	iter<int>(arr, 10, print<int>);
	iter<char>(brr, 10, print<char>);

	return 0;
}