#include "Span.hpp"

int main()
{
    try {
        Span sp = Span(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        sp.addRange(vec.begin(), vec.end());

        sp.displayNumbers();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}