#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = other.type;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
