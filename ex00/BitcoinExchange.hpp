#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
  private:
    std::string _inputFileName;
    std::string _dataFileName;
    std::map<std::string, float> _data;

    void parseCsvFile();
    std::pair<std::string, float> parseTxtFileByLine(std::string input);
    bool isValidNumber(const char *end, double number);
    void printResult(std::pair<std::string, float> pair);

    BitcoinExchange();

  public:
    BitcoinExchange(char *av, std::string fileName);
    BitcoinExchange(const BitcoinExchange &ref);
    ~BitcoinExchange();

    void execute();

    std::string getInputFileName() const;
    std::string getDataFileName() const;
    std::map<std::string, float> getData() const;

    BitcoinExchange &operator=(const BitcoinExchange &ref);
};

#endif