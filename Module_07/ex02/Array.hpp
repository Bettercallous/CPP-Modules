#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
    private:
        T* arr;
        unsigned int arrSize;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array & other);
        Array& operator=(const Array & other);
        ~Array();
        T& operator[] (unsigned int i);
        unsigned int size() const;
};

#include "Array.tpp"
#endif