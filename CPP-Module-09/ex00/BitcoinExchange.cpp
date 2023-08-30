#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *av, std::string fileName)
    : _inputFileName(av), _dataFileName(fileName) {
    if (fileName.substr(fileName.size() - 4, 4) != ".csv") {
        std::cout << "Error: invalid file extension." << std::endl;
        exit(EXIT_FAILURE);
    }
    parseCsvFile();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
    : _inputFileName(ref.getInputFileName()), _dataFileName(ref.getDataFileName()),
      _data(ref.getData()) {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseCsvFile() {
    std::ifstream targetStream;

    targetStream.open(_dataFileName);
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

        _data[date] = atof(value.c_str());
    }
    targetStream.close();
}

bool BitcoinExchange::isValidNumber(const char *end, double number) {
    if (*end != '\0')
        return false;
    if (number > 1000)
        throw std::out_of_range("too large number.");
    if (number < 0)
        throw std::out_of_range("not a positive number.");
    return true;
}

std::pair<std::string, float> BitcoinExchange::parseTxtFileByLine(std::string input) {
    size_t pos = input.find(" | ");
    if (pos == std::string::npos)
        throw std::invalid_argument("bad input => " + input);

    char *end;
    std::string date = input.substr(0, pos);
    double value = strtod(input.substr(pos + 3).c_str(), &end);

    if (isValidNumber(end, value))
        return std::pair<std::string, float>(date, value);
    else
        throw std::invalid_argument("bad input => " + input);
}

void BitcoinExchange::printResult(std::pair<std::string, float> input) {
    std::map<std::string, float>::iterator it = _data.lower_bound(input.first);

    if (it == _data.begin())
        throw std::invalid_argument("no such date.");
    if (it->first != input.first)
        it--;

    float floatRes = it->second * input.second;

    std::stringstream ss;
    std::string stringRes;

    ss << floatRes;
    stringRes = ss.str();

    if (stringRes.find('e') != std::string::npos) {
        std::cout << input.first << " => " << input.second << " = " << std::fixed
                  << std::setprecision(6) << round(floatRes * 1000000) / 1000000 << std::endl;
    } else {
        std::cout << input.first << " => " << input.second << " = " << stringRes << std::endl;
    }
}

void BitcoinExchange::execute() {
    std::ifstream inputStream;

    inputStream.open(_inputFileName);
    if (!inputStream) {
        std::cout << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;

    std::getline(inputStream, line);
    while (std::getline(inputStream, line)) {
        try {
            std::pair<std::string, float> inputPair = parseTxtFileByLine(line);
            printResult(inputPair);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    inputStream.close();
}

std::string BitcoinExchange::getInputFileName() const { return _inputFileName; }

std::string BitcoinExchange::getDataFileName() const { return _dataFileName; }

std::map<std::string, float> BitcoinExchange::getData() const { return _data; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
    if (this != &ref) {
        this->_inputFileName = ref.getInputFileName();
        this->_dataFileName = ref.getDataFileName();
        this->_data = ref.getData();
    }
    return *this;
}