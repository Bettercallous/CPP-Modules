#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	// std::cout << "Cure copy assignment operator called" << std::endl;
	if (_type != other._type)
		_type = other._type;
	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target) {
	ICharacter *p = &target;
	if (p)
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	return (new Cure());
}

