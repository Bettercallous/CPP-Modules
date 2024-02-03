#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN \"_expression_\"" << std::endl;
        return 1;
    }

    if (processExpression(av[1]) == false)
        return 1;

    try {
        std::cout << executeExpression(av[1]) << std::endl;
    } catch (int) {
        std::cerr << "Error: division by zero is undefined." << std::endl;
        return 1;
    } catch (char const*) {
        std::cerr << "Error: invalid RPN expression" << std::endl;
        return 1;
    }

    return 0;
}
