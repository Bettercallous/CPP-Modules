#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
	// std::cout << "AMateria default constructor called" << std::endl;
	this->type = "-";
}

AMateria::AMateria(std::string const& type) {
	// std::cout << "AMateria constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria& other) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this->type != other.type)
		this->type = other.type;
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
