#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
  private:
    std::string _line;
    std::stack<long long> _numberStack;

    int calculate(long long leftOperand, long long rightOperand, char op);

  public:
    RPN(std::string str);
    ~RPN();
    RPN(const RPN &ref);

    std::string getLine() const;
    std::stack<long long> getNumbers() const;
    int getResult();

    RPN &operator=(const RPN &ref);
};

#endif