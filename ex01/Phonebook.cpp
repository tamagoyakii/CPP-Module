#include "Phonebook.hpp"
#include <iomanip>

// Compare this snippet from ex01/Phonebook.cpp:

Phonebook::Phonebook() {
	this->_contactCount = 0;
}

Phonebook::~Phonebook() {
	return;
}

void Phonebook::addContact() {
	if (this->_contactCount == 8) {
		std::cout << "Phonebook is full" << std::endl;
		return;
	}
	this->_contacts[this->_contactCount].setFirstName();
	this->_contacts[this->_contactCount].setLastName();
	this->_contacts[this->_contactCount].setNickname();
	this->_contacts[this->_contactCount].setPhoneNumber();
	this->_contacts[this->_contactCount].setDarkestSecret();
	this->_contactCount++;
}

void Phonebook::searchContact() {
	std::string index;
	int i;

	if (this->_contactCount == 0) {
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (i = 0; i < this->_contactCount; i++) {
		std::cout << std::setw(10) << i << "|";
		if (this->_contacts[i].getFirstName().length() > 10)
			std::cout << this->_contacts[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].getFirstName() << "|";
		if (this->_contacts[i].getLastName().length() > 10)
			std::cout << this->_contacts[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].getLastName() << "|";
		if (this->_contacts[i].getNickname().length() > 10)
			std::cout << this->_contacts[i].getNickname().substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << this->_contacts[i].getNickname() << std::endl;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7' && index[0] - '0' < this->_contactCount)
		this->_contacts[index[0] - '0'].show();
	else
		std::cout << "Wrong index" << std::endl;
}

void Phonebook::showContact(int index) {
	this->_contacts[index].show();
}
// Compare this snippet from ex01/Contact.cpp:
