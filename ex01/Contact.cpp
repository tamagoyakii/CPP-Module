#include "Contact.hpp"

std::string Contact::getFirstName() const {
	return this->_firstName;
}

std::string Contact::getLastName() const {
	return this->_lastName;
}

std::string Contact::getNickname() const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}

void Contact::setFirstName() {
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->_firstName);
}

void Contact::setLastName() {
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->_lastName);
}

void Contact::setNickname() {
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->_nickname);
}

void Contact::setPhoneNumber() {
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->_phoneNumber);
}

void Contact::setDarkestSecret() {
	std::cout << "Enter your secret: ";
	std::getline(std::cin, this->_darkestSecret);
}

void Contact::show() const{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

Contact::Contact() {
	return;
}

Contact::~Contact() {
	return;
}
