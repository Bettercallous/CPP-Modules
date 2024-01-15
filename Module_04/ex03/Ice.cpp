#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	// std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	// std::cout << "Ice copy assignment operator called" << std::endl;
	if (_type != other._type)
		_type = other._type;
	return *this;
}

Ice::~Ice() {
	// std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter& target) {
	ICharacter *p = &target;
	if (p)
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}

AMateria* Ice::clone() const {
	return (new Ice());
}