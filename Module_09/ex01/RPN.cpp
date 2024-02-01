#include "RPN.hpp"

static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

static bool validTokens(const std::string& str) {
    return str.find_first_not_of("0123456789 /+-*") == std::string::npos;
}

static bool sufficentOperands(const std::string& input) {
    int operands = 0;
    int operators = 0;
    std::string ops("*/+-");

    for (size_t i = 0; i < input.length(); ++i) {
        if (isdigit(input[i])) {
            operands++;
        }
        else if (ops.find(input[i]) != std::string::npos)
            operators++;
    }
    if (operands == 1)
        return false;

    return operators == operands - 1;
}

std::string processExpression(const std::string& input) {
    
    if (validTokens(input) == false)
        return "";

    if (sufficentOperands(input) == false)
        return "";

    std::string s(trim(input));

    if (isdigit(s[s.length() - 1]))
        return "";

    return input;
}

int executeExpression(const std::string& expr) {
    std::stack<int> _stack;

    for (size_t i = 0; i < expr.length(); i++) {
        if (isspace(expr[i]))
            continue;
        else if (isdigit(expr[i]))
            _stack.push(expr[i] - 48);  
        else {
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
    return _stack.top();
}
