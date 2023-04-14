#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
  private:
    std::string _line;
    std::stack<double> _numberStack;

  public:
    RPN(std::string str);
    ~RPN();
    RPN(const RPN &ref);

    std::string getLine() const;
    std::stack<double> getNumbers() const;
    double getResult();

    RPN &operator=(const RPN &ref);
};

#endif