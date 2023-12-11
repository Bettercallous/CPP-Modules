#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
	// std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(std::string const& type) {
	// std::cout << "Ice constructor called" << std::endl;
	this->type = type;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	// std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	AMateria::operator=(other);
	// std::cout << "Ice copy assignment operator called" << std::endl;
	return *this;
}

Ice::~Ice() {
	// std::cout << "Ice destructor called" << std::endl;
}

std::string const& Ice::getType() const {
	return this->type;
}

void Ice::use(ICharacter& target) {
	ICharacter *p = &target;
	if (p)
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}

Ice* Ice::clone() const {
	return new Ice();
}