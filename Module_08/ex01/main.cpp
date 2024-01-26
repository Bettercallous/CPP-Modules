#include "Span.hpp"

void func(int& i) {
    i = std::rand();
}

int main()
{
    std::srand(time(0));
    try {
        Span sp = Span(100000);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::vector<int> arr(100000);
        std::for_each(arr.begin(), arr.end(), func);

        sp.addRange(arr.begin() + 5, arr.end());
        sp.displayNumbers();
        std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
