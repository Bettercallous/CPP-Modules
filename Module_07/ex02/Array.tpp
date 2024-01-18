#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(new T[0]), arrSize(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), arrSize(n) {}

template<typename T>
Array<T>::Array(const Array & other) : Array(other.arrSize) {
    for (unsigned int i = 0; i < arrSize; i++) {
        this->arr[i] = other.arr[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array & other) {
    if (this != &other) {
        delete[] this->arr;
        this->arr = new T[other.arrSize];
        this->arrSize = other.arrSize;
        for (unsigned int i = 0; i < this->arrSize; i++) {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[] (unsigned int i) {
    if (i >= this->arrSize)
        throw std::exception();
    return this->arr[i];
}

template<typename T>
Array<T>::~Array() {
    delete[] this->arr;
}

template<typename T>
unsigned int Array<T>::size() const {
    return this->arrSize;
}
