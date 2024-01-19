#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(NULL), arrSize(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), arrSize(n) {}

template<typename T>
Array<T>::Array(const Array & other) {
	arr = new T[other.arrSize];
	arrSize = other.arrSize;
	for (unsigned int i = 0; i < arrSize; i++) {
		arr[i] = other.arr[i];
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
T& Array<T>::operator[] (unsigned int i) const {
	if (i >= this->arrSize)
		throw OutOfBoundsException();
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

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Index is out of bounds";
}