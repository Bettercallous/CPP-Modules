#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "Materiasource default constructor called" << std::endl;
}

Materiasource::MateriaSource(const MateriaSource & other) {
	std::cout << "Materiasource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource& operator=(const MateriaSource & other) {
	std::cout << "Materiasource copy assignment operator called" << std::endl;

}

Materiasource::~MateriaSource() {
	std::cout << "Materiasource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* amateria) {

}

AMateria* MateriaSource::createMateria(std::string const & type) {

}
