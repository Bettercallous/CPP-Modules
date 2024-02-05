#include "Span.hpp"

void func(int& i) {
    i = std::rand();
}

int main()
{
    try {
        Span sp = Span(10000);
        sp.addNumber(6);
        sp.addNumber(8);
        sp.addNumber(5);
        sp.addNumber(4);
        sp.addNumber(2);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::vector<int> arr(10000);
        std::srand(time(0));
        std::for_each(arr.begin(), arr.end(), func);

        sp.addRange(arr.begin() + 5, arr.end());
        // sp.displayNumbers();
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
