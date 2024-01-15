#include "Fixed.hpp"

Fixed::Fixed() {
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = f.getRawBits();
	return *this;
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
