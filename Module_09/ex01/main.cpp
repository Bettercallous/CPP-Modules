#include "RPN.hpp"

// std::string trim(const std::string& str) {
//     size_t first = str.find_first_not_of(' ');
//     if (first == std::string::npos)
//         return str;
//     size_t last = str.find_last_not_of(' ');
//     return str.substr(first, (last - first + 1));
// }

bool validTokens(const std::string& str) {
    return str.find_first_not_of("0123456789 /+-*") == std::string::npos;
}

bool sufficentOperands(const std::string& input) {
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

    std::cout << operands << " " << operators << std::endl;
    return operators == operands - 1;
}

std::string processExpression(const std::string& input) {
    
    if (validTokens(input) == false)
        return "";

    if (sufficentOperands(input) == false)
        return "";

    return input;
}

int executeExpression(const std::string& expr) {
    (void)expr;
    std::stack<int> _stack;

    // std::string expr("89*9-9-9-4-1+");
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
            else if (expr[i] == '/')
                _stack.push(a / b);
            else if (expr[i] == '+')
                _stack.push(a + b);
            else if (expr[i] == '-')
                _stack.push(a - b);
        }
    }
    return _stack.top();
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN _expression_" << std::endl;
        return 1;
    }

    std::string expr = processExpression(av[1]);

    if (expr.empty()) {
        std::cerr << "Error: invalid expression" << std::endl;
        return 1;
    }

    std::cout << executeExpression(expr) << std::endl;

    return 0;
}






/*

Invalid Tokens: Ensure that each token in the expression is valid. Valid tokens typically include numbers and operators. If you encounter an invalid token, such as a letter or a symbol that is not recognized as part of the RPN syntax, you should raise an error indicating that the expression is malformed.

Insufficient Operands: In RPN, each operator requires a certain number of operands to perform the operation. For example, addition requires two operands, subtraction requires two operands, etc. If you encounter an operator without a sufficient number of operands on the stack, it indicates a syntax error in the expression.

Extra Operands: Conversely, if you reach the end of the expression and there are still operands remaining on the stack, it indicates that there were insufficient operators in the expression, which is also an error.

Division by Zero: If you encounter a division operator (/) with zero as the divisor, you should handle this as a special case and raise an error to avoid dividing by zero, which is undefined in arithmetic.

*/