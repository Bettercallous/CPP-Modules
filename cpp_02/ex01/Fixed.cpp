#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() {
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	this->fixedPoint = other.fixedPoint;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int fixedp) {
	this->fixedPoint = this->fixedPoint << this->fractionalBits;
}

void Fixed::operator=(const Fixed& f) {
	this->fixedPoint = f.fixedPoint;
	std::cout << "Copy assignment operator called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

float Fixed::toFloat() const {
	return (float)(fixedPoint >> fractionalBits);
}

int Fixed::toInt() const {
	return fixedPoint >> fractionalBits;
}