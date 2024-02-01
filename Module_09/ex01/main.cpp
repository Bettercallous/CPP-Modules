#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN _expression_" << std::endl;
        return 1;
    }

    std::string expr = processExpression(av[1]);

    if (expr.empty()) {
        std::cerr << "Error: invalid RPN expression" << std::endl;
        return 1;
    }

    try {
        std::cout << executeExpression(expr) << std::endl;
    } catch (int) {
        std::cout << "Error: division by zero is undefined." << std::endl;
        return 1;
    }

    return 0;
}
