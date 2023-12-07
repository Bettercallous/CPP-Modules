#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "Cat";
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->type = other.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const {
    return this->type;
}

void WrongCat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
