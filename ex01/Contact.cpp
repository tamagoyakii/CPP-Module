#include "Contact.hpp"

Contact::Contact() {
	return;
}

Contact::~Contact() {
	return;
}

void Contact::setFirstName() {
	std::string s;

	while (s.length() == 0 && !std::cin.fail()) {
		std::cout << "Input first name: ";
		std::getline(std::cin, s);
	}
	this->_firstName = replaceTab(s);
}

void Contact::setLastName() {
	std::string s;

	while (s.length() == 0 && !std::cin.fail()) {
		std::cout << "Input last name: ";
		std::getline(std::cin, s);
	}
	this->_lastName = replaceTab(s);
}

void Contact::setNickname() {
	std::string s;

	while (s.length() == 0 && !std::cin.fail()) {
		std::cout << "Input nickname: ";
		std::getline(std::cin, s);
	}
	this->_nickname = replaceTab(s);
}

void Contact::setPhoneNumber() {
	std::string s;

	while (s.length() == 0 && !std::cin.fail()) {
		std::cout << "Input phone number: ";
		std::getline(std::cin, s);
	}
	this->_phoneNumber = replaceTab(s);
}

void Contact::setDarkestSecret() {
	std::string s;

	while (s.length() == 0 && !std::cin.fail()) {
		std::cout << "Input darkest secret: ";
		std::getline(std::cin, s);
	}
	this->_darkestSecret = replaceTab(s);
}

void Contact::show() {
	if (this->_firstName.length() == 0) {
		std::cout << "It's EMPTY!!!" << std::endl;
		return;
	}
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

std::string Contact::replaceTab(std::string value) {
	for (int i = 0; i < (int) value.length(); i++) {
		if (value[i] == '\t') value.replace(i, 1, " ");
	}
	return value;
}

std::string Contact::getFirstName(int sub) {
	if (sub && this->_firstName.length() > 10) return this->_firstName.substr(0, 9) + '.';
	return this->_firstName;
}

std::string Contact::getLastName(int sub) {
	if (sub && this->_lastName.length() > 10) return this->_lastName.substr(0, 9) + '.';
	return this->_lastName;
}

std::string Contact::getNickname(int sub) {
	if (sub && this->_nickname.length() > 10) return this->_nickname.substr(0, 9) + '.';
	return this->_nickname;
}

std::string Contact::getPhoneNumber() {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return this->_darkestSecret;
}