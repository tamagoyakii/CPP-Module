#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <ctime>

class BitcoinExchange {
	private:
		std::ifstream _inputStream;
		std::ifstream _targetStream;
		std::map<std::string, float> _targetData;

		std::ifstream openFile(std::string fileName);
		void parseTargetData();
	public:
		BitcoinExchange(char* av);
		BitcoinExchange(const BitcoinExchange& ref);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& ref);
		void printExchange();

		class NegativeNumberException : public std::exception {
			public:
				const char* what() const throw();
		};

		class TooLargeNumberException : public std::exception {
			public:
				const char* what() const throw();
		};

		class BadInputException : public std::exception {
				std::string* _message;
			public:
				BadInputException(std::string& str) throw();
				~BadInputException() throw();
				const char* what() const throw();
		};
};

#endif