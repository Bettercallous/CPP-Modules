#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() {
	this->fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = num << this->fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(num * 256);
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = f.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

float Fixed::toFloat() const {
	return (float)getRawBits() / 256;
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
	Fixed fp;
	fp.setRawBits(this->fixedPoint + f.fixedPoint);
	return fp;
}

Fixed Fixed::operator-(const Fixed& f) const {
	Fixed fp;
	fp.setRawBits(this->fixedPoint - f.fixedPoint);
	return fp;
}

Fixed Fixed::operator*(const Fixed& f) const {
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed& f) const {
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed& Fixed::operator++() {
	this->fixedPoint++;
	return *this;
}

Fixed& Fixed::operator--() {
	this->fixedPoint--;
	return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    this->operator++();
	return old;
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    this->operator--();
	return old;
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
