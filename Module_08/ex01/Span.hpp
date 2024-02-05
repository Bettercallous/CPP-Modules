#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <exception>
#include <cstdlib>

class Span {
    private:
        std::vector<int> values;
        unsigned int capacity;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span & other);
        Span& operator=(const Span & other);
        ~Span();

        void addNumber(int num);
        long shortestSpan() const;
        long longestSpan() const;
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void displayNumbers();
};

#endif