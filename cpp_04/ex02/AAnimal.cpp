#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called" << std::endl;
	type = "Unknown Animal";
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::setType(std::string type)
{
	this->type = type;
}