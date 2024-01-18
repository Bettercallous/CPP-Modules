#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(new T[0]), size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), size(n) {}

template<typename T>
Array<T>::Array(const Array & other) : Array(other.size) {
    for (unsigned int i = 0; i < size; i++) {
        this->arr[i] = other.arr[i];
    }
}

template<typename T>
Array& Array<T>::operator=(const Array & other) {
    if (this != &other) {
        delete[] this->arr;
        this->arr = new T[other.size];
        this->size = other.size;
        for (unsigned int i = 0; i < this->size; i++) {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[] (unsigned int i) {
    if (i < 0 || i > this->size)
        throw std::exeption("exception: Index out of bounds");
    return this->arr[i];
}

template<typename T>
Array<T>::~Array() {
    delete[] this->arr;
}

template<typename T>
unsigned int Array<T>::size() const {
    return this->size;
}
