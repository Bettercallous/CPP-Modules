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
		T& operator[] (unsigned int i) const;
		unsigned int size() const;

		class OutOfBoundsException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#include "Array.tpp"
#endif