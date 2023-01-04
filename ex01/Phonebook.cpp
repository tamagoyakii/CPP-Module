#include "Phonebook.hpp"
#include <iomanip>

Phonebook::Phonebook() {
	this->_contactCount = 0;
}

Phonebook::~Phonebook() {
	return;
}

void Phonebook::addContact() {
	if (this->_contactCount == 8) this->_contactCount = 0;
	this->_contacts[this->_contactCount].setFirstName();
	if (std::cin.fail()) return;
	this->_contacts[this->_contactCount].setLastName();
	if (std::cin.fail()) return;
	this->_contacts[this->_contactCount].setNickname();
	if (std::cin.fail()) return;
	this->_contacts[this->_contactCount].setPhoneNumber();
	if (std::cin.fail()) return;
	this->_contacts[this->_contactCount].setDarkestSecret();
	if (std::cin.fail()) return;
	this->_contactCount++;
}

void Phonebook::searchContact() {
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << i << "|" 
		<< std::setw(10) << this->_contacts[i].getFirstName(1) << "|" 
		<< std::setw(10) << this->_contacts[i].getLastName(1) << "|" 
		<< std::setw(10) << this->_contacts[i].getNickname(1) << std::endl;
	}
	showContact();
}

void Phonebook::showContact() {
	std::string	index;

	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	if (std::cin.fail()) return;
	if (index.length() == 1 && index[0] >= '0' && index[0] < '8')
		this->_contacts[index[0] - '0'].show();
	else
		std::cout << "Wrong index!" << std::endl;
}
