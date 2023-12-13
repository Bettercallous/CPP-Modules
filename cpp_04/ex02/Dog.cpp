#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		*this->brain = *other.brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

std::string Dog::getType() const {
	return this->type;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
