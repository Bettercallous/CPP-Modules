#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const {
	return _type;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
