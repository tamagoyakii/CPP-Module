#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class Phonebook {
	private:
		Contact _contacts[8];
		int _contactCount;
	public:
		Phonebook();
		~Phonebook();
		void addContact();
		void searchContact();
		void showContact(int index);
};

#endif