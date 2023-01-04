#include "Phonebook.hpp"
#include <iomanip>

int main() {
	Phonebook phonebook;
	std::string command;

	while (1) {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (std::cin.fail()) break;
		
		if (command == "EXIT") break;
		else if (command == "ADD") phonebook.addContact();
		else if (command == "SEARCH") phonebook.searchContact();
		if (std::cin.fail()) break;
	}
	return 0;
}