#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

std::string Dog::getType() const {
	return _type;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
