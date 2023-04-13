#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange {
  private:
    std::string _inputFile;
    std::string _targetFile;
    std::map<std::string, float> _targetData;

    std::ifstream openFile(std::string fileName);
    void parseTargetData();

  public:
    BitcoinExchange(char *av);
    BitcoinExchange(const BitcoinExchange &ref);
    ~BitcoinExchange();

    void printExchange();

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

class BadInputException : public std::exception {
    std::string *_message;

  public:
    BadInputException(std::string &str) throw();
    ~BadInputException() throw();
    const char *what() const throw();
};

#endif