#include "Span.hpp"

Span::Span() : capacity(0) {}

Span::Span(unsigned int N) : capacity(N) {
    values.reserve(capacity);
}

Span::Span(const Span & other) : values(other.values), capacity(other.capacity) {}

Span& Span::operator=(const Span & other) {
    if (this != &other) {
        capacity = other.capacity;
        values = other.values;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (values.size() >= capacity)
        throw std::out_of_range("Span is full, can't add more numbers");
    values.push_back(num);
}

int Span::shortestSpan() const {
    if (values.size() < 2)
        throw std::logic_error("Can't find span with less than 2 numbers");

    std::vector<int> sortedNumbers(values);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = INT_MAX;

    for (size_t i = 1; i < sortedNumbers.size(); i++) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (values.size() < 2)
        throw std::logic_error("Can't find span with less than 2 numbers");

    std::vector<int> sortedNumbers(values);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    return sortedNumbers.back() - sortedNumbers.front();
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t addedSize = std::distance(begin, end);
    if (values.size() + addedSize > capacity)
        throw std::out_of_range("Not enough space to add the given numbers.");
    values.insert(values.end(), begin, end);
}

void print(int i) {
    std::cout << i << " ";
}

void Span::displayNumbers() {
    std::for_each(values.begin(), values.end(), print);
    std::cout << std::endl;
}
