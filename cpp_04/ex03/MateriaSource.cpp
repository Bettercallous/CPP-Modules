#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "Materiasource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
        this->materials[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		if (other.materials[i]) {
			this->materials[i] = other.materials[i]->clone();
		} else {
			this->materials[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other) {

		for (int i = 0; i < 4; i++) {
			delete this->materials[i];
			this->materials[i] = NULL;
		}

		for (int i = 0; i < 4; i++) {
			if (other.materials[i] != NULL) {
				this->materials[i] = other.materials[i]->clone();
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	// std::cout << "Materiasource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
        delete this->materials[i];
        this->materials[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
		return;
	for (int i = 0; i < 4; i++) {
        if (!this->materials[i]) {
            this->materials[i] = m;
            return;
        }
    }
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    // std::cout << this->materials[0]->getType() << std::endl;
    // std::cout << this->materials[1]->getType() << std::endl;
	for (int i = 0; i < 4; i++) {
        if (this->materials[i] && this->materials[i]->getType() == type) {
            return this->materials[i]->clone();
        }
    }
    return NULL;
}