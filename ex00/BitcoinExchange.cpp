#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char* av): _inputStream(openFile(av)), _targetStream(openFile("data.csv")) {
	parseTargetData();
}

BitcoinExchange::~BitcoinExchange() {}

std::ifstream BitcoinExchange::openFile(std::string fileName) {
	std::ifstream stream;

	stream.open(fileName);
	if (!stream) {
		std::cout << "Error: could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	return stream;
}

void BitcoinExchange::parseTargetData() {
	std::string line;

	std::getline(_targetStream, line);
	while (std::getline(_targetStream, line)) {
		size_t pos = line.find(",");
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1);

		_targetData[date] = atof(value.c_str());
	}
}

void BitcoinExchange::printExchange() {
	std::string line;

	std::getline(_inputStream, line);
	while (std::getline(_inputStream, line)) {
		try {
			size_t pos = line.find(" | ");
			if (pos == std::string::npos) throw BadInputException(line);

			std::string date = line.substr(0, pos);
			std::string value = line.substr(pos + 3);

			if (atol(value.c_str()) > 1000) throw TooLargeNumberException();
			if (atol(value.c_str()) < 0) throw NegativeNumberException();

			std::map<std::string, float>::iterator iter = _targetData.lower_bound(date);

			if (iter == _targetData.begin()) throw BadInputException(line);
			std::cout << date << " => " << value << " = " << (--iter)->second * atof(value.c_str()) << std::endl;
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

const char* BitcoinExchange::NegativeNumberException::what() const throw() {
	return "not a positive number.";
}

const char* BitcoinExchange::TooLargeNumberException::what() const throw() {
	return "too large number.";
}

BitcoinExchange::BadInputException::BadInputException(std::string& str) throw() {
	_message = new std::string("bad input => " + str);
}

BitcoinExchange::BadInputException::~BadInputException() throw() {
	delete _message;
}

const char* BitcoinExchange::BadInputException::what() const throw() {
	return _message->c_str();
}
