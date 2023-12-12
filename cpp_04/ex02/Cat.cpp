#include "Cat.hpp"

Cat::Cat() : AAnimal() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

std::string Cat::getType() const {
    return this->type;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
