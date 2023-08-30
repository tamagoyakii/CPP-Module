#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
	private:
		std::string _phrase;
		Data(void);
	public :
		Data(std::string phrase);
		Data(const Data& ref);
		Data& operator=(const Data& ref);
		~Data(void);

		std::string getPhrase(void) const;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif