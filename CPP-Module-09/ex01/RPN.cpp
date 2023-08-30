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

std::stack<long long> RPN::getNumbers() const { return _numberStack; }

int RPN::calculate(long long leftOperand, long long rightOperand, char op) {
    long long result;

    switch (op) {
    case '+':
        result = leftOperand + rightOperand;
        break;
    case '-':
        result = leftOperand - rightOperand;
        break;
    case '*':
        result = leftOperand * rightOperand;
        break;
    case '/':
        if (rightOperand == 0)
            throw std::out_of_range("no division by zero.");
        result = leftOperand / rightOperand;
    }
    if (result > INT_MAX || result < INT_MIN)
        throw std::out_of_range("overflow.");
    return result;
}

int RPN::getResult() {
    std::stringstream lineStream(_line);
    std::string token;
    int number;

    while (lineStream >> token) {
        if (token.length() > 1)
            throw std::invalid_argument("invalid element.");
        if (isdigit(token[0])) {
            std::istringstream(token) >> number;
            _numberStack.push(number);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_numberStack.size() < 2)
                throw std::invalid_argument("not enough stack.");

            int rightOperand = _numberStack.top();
            _numberStack.pop();
            int leftOperand = _numberStack.top();
            _numberStack.pop();

            _numberStack.push(calculate(leftOperand, rightOperand, token[0]));
        } else {
            throw std::invalid_argument("invalid element.");
        }
    }
    if (_numberStack.size() != 1)
        throw std::invalid_argument("finish the operation.");
    return _numberStack.top();
}
