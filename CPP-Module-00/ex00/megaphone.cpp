#include <iostream>
# define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << DEFAULT << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++) {
		std::string s(av[i]);
		for (int j = 0; j < (int) s.length(); j++) std::cout << (char) toupper(s[j]);
	}
	std::cout << std::endl;
	return (0);
}