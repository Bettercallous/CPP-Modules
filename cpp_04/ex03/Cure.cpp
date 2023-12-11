#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
	// std::cout << "Cure default constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(std::string const& type) {
	// std::cout << "Cure constructor called" << std::endl;
	this->type = type;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    AMateria::operator=(other);
	// std::cout << "Cure copy assignment operator called" << std::endl;
	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}

// std::string const& Cure::getType() const {
// 	return this->type;
// }

void Cure::use(ICharacter& target) {
    ICharacter *p = &target;
    if (p)
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
    return (new Cure());
}

