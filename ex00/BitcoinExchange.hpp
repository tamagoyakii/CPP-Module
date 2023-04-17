#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
// #include <sstream>

class BitcoinExchange {
  private:
    std::string _inputFile;
    std::string _targetFile;
    std::map<std::string, float> _targetData;

    std::ifstream openFile(std::string fileName);
    void parseTargetData();
    std::pair<std::string, std::string> validateInput(std::string input);
    void validateValue(std::string str);
    void printResult(std::pair<std::string, std::string> pair);

  public:
    BitcoinExchange(char *av);
    BitcoinExchange(const BitcoinExchange &ref);
    ~BitcoinExchange();

    void execute();

    std::string getInputFile() const;
    std::string getTargetFile() const;
    std::map<std::string, float> getTargetData() const;

    BitcoinExchange &operator=(const BitcoinExchange &ref);
};

class NegativeNumberException : public std::exception {
  public:
    const char *what() const throw();
};

class TooLargeNumberException : public std::exception {
  public:
    const char *what() const throw();
};

class TooLongDecimalException : public std::exception {
  public:
    const char *what() const throw();
};

class NoSuchDateException : public std::exception {
  public:
    const char *what() const throw();
};
class BadInputException : public std::exception {
    std::string *_message;

  public:
    BadInputException(std::string &str) throw();
    ~BadInputException() throw();
    const char *what() const throw();
};

#endif