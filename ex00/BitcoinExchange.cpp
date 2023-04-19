#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *av) : _inputFile(av), _targetFile("data.csv") {
    parseTargetData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
    : _inputFile(ref.getInputFile()), _targetFile(ref.getTargetFile()),
      _targetData(ref.getTargetData()) {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseTargetData() {
    std::ifstream targetStream;
    
    targetStream.open(_targetFile);
    if (!targetStream) {
        std::cout << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;

    std::getline(targetStream, line);
    while (std::getline(targetStream, line)) {
        size_t pos = line.find(",");
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        _targetData[date] = atof(value.c_str());
    }
}

std::pair<std::string, std::string> BitcoinExchange::validateInput(std::string input) {
    size_t pos = input.find(" | ");
    if (pos == std::string::npos)
        throw BadInputException(input);

    std::string date = input.substr(0, pos);
    std::string value = input.substr(pos + 3);
    int pointFlag = 0;

    for (size_t i = 0; i < value.length(); ++i) {
        if (value[i] == '-') {
            if (i != 0)
                throw BadInputException(input);
        } else if (value[i] == '.') {
            if (pointFlag)
                throw BadInputException(input);
            pointFlag = 1;
        } else if (!isdigit(value[i])) {
            throw BadInputException(input);
        }
    }
    return std::pair<std::string, std::string>(date, value);
}

void BitcoinExchange::validateValue(std::string str) {
    size_t pos = str.find(".");

    if (pos != std::string::npos && str.substr(pos + 1).length() > 6)
        throw TooLongDecimalException();

    double value = strtod(str.c_str(), NULL);

    if (value > 1000)
        throw TooLargeNumberException();
    if (value < 0)
        throw NegativeNumberException();
}

void BitcoinExchange::printResult(std::pair<std::string, std::string> pair) {
    std::map<std::string, float>::iterator it = _targetData.lower_bound(pair.first);

    if (it == _targetData.begin())
        throw NoSuchDateException();
    if (it->first != pair.first)
        it--;

    float floatRes = it->second * atof(pair.second.c_str());

    std::stringstream ss;
    std::string stringRes;

    ss << floatRes;
    stringRes = ss.str();

    if (stringRes.find('e') != std::string::npos) {
        std::cout << pair.first << " => " << pair.second << " = " << std::fixed
                  << std::setprecision(6) << round(floatRes * 1000000) / 1000000 << std::endl;
    } else {
        std::cout << pair.first << " => " << pair.second << " = " << stringRes << std::endl;
    }
}

void BitcoinExchange::execute() {
    std::ifstream inputStream;
    
    inputStream.open(_inputFile);
    if (!inputStream) {
        std::cout << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;

    std::getline(inputStream, line);
    while (std::getline(inputStream, line)) {
        try {
            std::pair<std::string, std::string> pair = validateInput(line);

            validateValue(pair.second);
            printResult(pair);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

std::string BitcoinExchange::getInputFile() const { return _inputFile; }

std::string BitcoinExchange::getTargetFile() const { return _targetFile; }

std::map<std::string, float> BitcoinExchange::getTargetData() const { return _targetData; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
    if (this != &ref) {
        this->_inputFile = ref.getInputFile();
        this->_targetFile = ref.getTargetFile();
        this->_targetData = ref.getTargetData();
    }
    return *this;
}

const char *NegativeNumberException::what() const throw() { return "not a positive number."; }

const char *TooLargeNumberException::what() const throw() { return "too large number."; }

const char *TooLongDecimalException::what() const throw() { return "too long decimal."; }

const char *NoSuchDateException::what() const throw() { return "no such date."; }

BadInputException::BadInputException(std::string &str) throw() {
    _message = new std::string("bad input => " + str);
}

BadInputException::~BadInputException() throw() { delete _message; }

const char *BadInputException::what() const throw() { return _message->c_str(); }
