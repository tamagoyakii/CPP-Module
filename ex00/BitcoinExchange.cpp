#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *av)
    : _inputFile(av), _targetFile("data.csv") {
    parseTargetData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
    : _inputFile(ref.getInputFile()), _targetFile(ref.getTargetFile()),
      _targetData(ref.getTargetData()) {}

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
    std::ifstream targetStream = openFile(_targetFile);
    std::string line;

    std::getline(targetStream, line);
    while (std::getline(targetStream, line)) {
        size_t pos = line.find(",");
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        _targetData[date] = atof(value.c_str());
    }
}

void BitcoinExchange::printExchange() {
    std::ifstream inputStream = openFile(_inputFile);
    std::string line;

    std::getline(inputStream, line);
    while (std::getline(inputStream, line)) {
        try {
            size_t pos = line.find(" | ");
            if (pos == std::string::npos)
                throw BadInputException(line);

            std::string date = line.substr(0, pos);
            std::string value = line.substr(pos + 3);

            if (atol(value.c_str()) > 1000)
                throw TooLargeNumberException();
            if (atol(value.c_str()) < 0)
                throw NegativeNumberException();

            std::map<std::string, float>::iterator iter =
                _targetData.lower_bound(date);

            if (iter == _targetData.begin())
                throw BadInputException(line);
            std::cout << date << " => " << value << " = "
                      << (--iter)->second * atof(value.c_str()) << std::endl;
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

std::string BitcoinExchange::getInputFile() const { return _inputFile; }

std::string BitcoinExchange::getTargetFile() const { return _targetFile; }

std::map<std::string, float> BitcoinExchange::getTargetData() const {
    return _targetData;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
    if (this != &ref) {
        this->_inputFile = ref.getInputFile();
        this->_targetFile = ref.getTargetFile();
        this->_targetData = ref.getTargetData();
    }
    return *this;
}

const char *NegativeNumberException::what() const throw() {
    return "not a positive number.";
}

const char *TooLargeNumberException::what() const throw() {
    return "too large number.";
}

BadInputException::BadInputException(std::string &str) throw() {
    _message = new std::string("bad input => " + str);
}

BadInputException::~BadInputException() throw() { delete _message; }

const char *BadInputException::what() const throw() {
    return _message->c_str();
}
