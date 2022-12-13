#include "Phonebook.hpp"

int main() {
	Phonebook phonebook;
	std::string command;

	while (1) {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
	}
	return 0;
}