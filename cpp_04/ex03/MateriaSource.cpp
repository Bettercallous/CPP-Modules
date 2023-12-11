#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "Materiasource default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i) {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;

	for (int i = 0; i < 4; ++i) {
		if (other.materias[i] != NULL) {
			materias[i] = other.materias[i]->clone();
		} else {
			materias[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other) {
		// Delete existing resources
		for (int i = 0; i < 4; ++i) {
			delete materias[i];
		}

		// Copy data from the other object
		for (int i = 0; i < 4; ++i) {
			if (other.materias[i] != NULL) {
				materias[i] = other.materias[i]->clone();
			} else {
				materias[i] = NULL;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	// std::cout << "Materiasource destructor called" << std::endl;
	for (int i = 0; i < 4; ++i) {
        delete materias[i];
        materias[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
        if (materias[i] == NULL) {
            materias[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    return NULL;
}