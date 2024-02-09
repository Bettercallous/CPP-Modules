#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & other) {*this = other;}

RPN& RPN::operator=(const RPN & other) {
    if (this != & other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}


bool RPN::processExpression(const std::string& input) {
    if (input.empty()) {
        std::cerr << "Error: empty argument" << std::endl;
        return false;
    }

    if (input.find_first_not_of("0123456789 /+-*") != std::string::npos) {
        std::cerr << "Error: invalid RPN expression" << std::endl;
        return false;
    }

    for (size_t i = 0; i < input.length() - 1; i++) {
        if (input[i] != '0') {
            if (isdigit(input[i]) && isdigit(input[i + 1])) {
                std::cerr << "Error: numbers must be less than 10" << std::endl;
                return false;
            }
        }
    }

    return true;
}

int RPN::executeExpression(const std::string& expr) {

    for (size_t i = 0; i < expr.length(); i++) {
        if (isspace(expr[i]))
            continue;
        while (expr[i] == '0' && isdigit(expr[i + 1]))
            i++;
        if (isdigit(expr[i]))
            _stack.push(expr[i] - 48);
        else {
            if (_stack.size() <= 1)
                throw "Error";
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            if (expr[i] == '*')
                _stack.push(a * b);
            else if (expr[i] == '+')
                _stack.push(a + b);
            else if (expr[i] == '-')
                _stack.push(a - b);
            else {
                if (b == 0)
                    throw -1;
                _stack.push(a / b);
            }
        }
    }
    if (_stack.size() != 1)
        throw "Error";
    return _stack.top();
}
