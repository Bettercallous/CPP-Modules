#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		_materials[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		if (other._materials[i]) {
			_materials[i] = other._materials[i]->clone();
		} else {
			_materials[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other) {

		for (int i = 0; i < 4; i++) {
			delete _materials[i];
			_materials[i] = NULL;
		}

		for (int i = 0; i < 4; i++) {
			if (other._materials[i] != NULL) {
				_materials[i] = other._materials[i]->clone();
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	// std::cout << "Materiasource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_materials[i])
			delete _materials[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_materials[i]) {
			_materials[i] = m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materials[i] && _materials[i]->getType() == type) {
			return _materials[i]->clone();
		}
	}
	return NULL;
}