#include "Harl.hpp"

Harl::Harl() {
	_level[0] = "DEBUG";
	_level[1] = "INFO";
	_level[2] = "WARNING";
	_level[3] = "ERROR";
	_ptrFunc[0] = &Harl::debug;
	_ptrFunc[1] = &Harl::info;
	_ptrFunc[2] = &Harl::warning;
	_ptrFunc[3] = &Harl::error;
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger." << std::endl
	<< "I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl
	<< "I cannot believe adding extra bacon costs more money." << std::endl
	<< "You didn’t put enough bacon in my burger!" << std::endl
	<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl
	<< "I think I deserve to have some extra bacon for free." << std::endl
	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl
	<< "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	int flag = -1;

	for (int i = 0; i < 4; i++) if (level == _level[i]) flag = i;
	switch (flag) {
		case 0:
			(this->*_ptrFunc[0])();
		case 1:
			(this->*_ptrFunc[1])();
		case 2:
			(this->*_ptrFunc[2])();
		case 3:
			(this->*_ptrFunc[3])();
			break;
		default:
			std::cout << "[ INVALID LEVEL ]" << std::endl;
	}
}