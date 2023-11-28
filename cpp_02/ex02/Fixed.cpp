#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() {
	this->fixedPoint = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num) {
	// std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = num * (1 << this->fractionalBits);
}

Fixed::Fixed(const float num) {
	// std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(num * (1 << this->fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& f) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = f.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
   return out << f.toFloat();
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

float Fixed::toFloat() const {
	return (float)getRawBits() / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return getRawBits() >> fractionalBits;
}

bool Fixed::operator< (const Fixed& f) const {
	return this->fixedPoint < f.fixedPoint;
}

bool Fixed::operator> (const Fixed& f) const {
	return this->fixedPoint > f.fixedPoint;
}

bool Fixed::operator<=(const Fixed& f) const {
	return this->fixedPoint <= f.fixedPoint;
}

bool Fixed::operator>=(const Fixed& f) const {
	return this->fixedPoint >= f.fixedPoint;
}

bool Fixed::operator==(const Fixed& f) const {
	return this->fixedPoint == f.fixedPoint;
}

bool Fixed::operator!=(const Fixed& f) const {
	return this->fixedPoint != f.fixedPoint;
}

Fixed Fixed::operator+(const Fixed& f) const {
	return this->toFloat() + f.toFloat();
}

Fixed Fixed::operator-(const Fixed& f) const {
	return this->toFloat() - f.toFloat();
}

Fixed Fixed::operator*(const Fixed& f) const {
	return this->toFloat() * f.toFloat();
}

Fixed Fixed::operator/(const Fixed& f) const {
	return this->toFloat() / f.toFloat();
}

Fixed& Fixed::operator++() {
	this->fixedPoint++;
	return *this; // return new value by reference
}

Fixed& Fixed::operator--() {
	this->fixedPoint--;
	return *this; // return new value by reference
}

Fixed Fixed::operator++(int) {
    Fixed old = *this; // copy old value
    this->operator++();  // prefix increment
	return old;    // return old value
}

Fixed Fixed::operator--(int) {
    Fixed old = *this; // copy old value
    this->operator--();  // prefix decrement
	return old;    // return old value
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}


/*
	the int parameter without a name doesn't serve any purpose within the implementation
	of the function. Its presence is a requirement of the language to differentiate between
	the prefix and postfix versions of the operators.
*/