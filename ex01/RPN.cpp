#include "RPN.hpp"

RPN::RPN(std::string str) : _line(str) {}

RPN::~RPN() {}

RPN::RPN(const RPN &ref) : _line(ref.getLine()), _numberStack(ref.getNumbers()) {}

RPN &RPN::operator=(const RPN &ref) {
    if (this != &ref) {
        this->_line = ref.getLine();
        this->_numberStack = ref.getNumbers();
    }
    return *this;
}

std::string RPN::getLine() const { return _line; }

std::stack<double> RPN::getNumbers() const { return _numberStack; }

double RPN::getResult() {
    std::stringstream lineStream(_line);
    std::string token;
    double number;

    while (lineStream >> token) {
        if (isdigit(token[0])) {
            std::istringstream(token) >> number;
            _numberStack.push(number);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            double rightOperand = _numberStack.top();
            _numberStack.pop();
            double leftOperand = _numberStack.top();
            _numberStack.pop();

            if (token == "+")
                _numberStack.push(leftOperand + rightOperand);
            else if (token == "-")
                _numberStack.push(leftOperand - rightOperand);
            else if (token == "*")
                _numberStack.push(leftOperand * rightOperand);
            else if (token == "/")
                _numberStack.push(leftOperand / rightOperand);
        } else {
            throw token;
        }
    }
    return _numberStack.top();
}
