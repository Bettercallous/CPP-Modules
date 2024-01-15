#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called" << std::endl;
    _type = "Cat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const {
    return _type;
}

void WrongCat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
