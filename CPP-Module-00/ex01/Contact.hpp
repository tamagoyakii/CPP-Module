#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact();
		~Contact();
		void setFirstName();
		void setLastName();
		void setNickname();
		void setPhoneNumber();
		void setDarkestSecret();
		void show();
		std::string replaceTab(std::string value);
		std::string getFirstName(int sub);
		std::string getLastName(int sub);
		std::string getNickname(int sub);
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif