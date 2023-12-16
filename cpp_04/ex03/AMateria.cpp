#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
	// std::cout << "AMateria default constructor called" << std::endl;
	_type = "Unnamed";
}

AMateria::AMateria(std::string const& type) {
	// std::cout << "AMateria constructor called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria& other) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	if (_type != other._type)
		_type = other._type;
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
