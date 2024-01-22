#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
    private:
        std::vector<int> *values;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span & other);
        Span& operator= (const Span & other);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
        //  Implement a member function to add many numbers to your Span in one call.
}

#endif