#include "Character.hpp"

Character::Character() {
	std::cout << "Character default constructor called" << std::endl;
	this->name = "";
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(std::string name) {
	std::cout << "Character constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(const Character& other) {
	std::cout << "Character copy constructor called" << std::endl;
	this->name = other.name;
	for (int i = 0; i < 4; ++i) {
		if (other.materias[i] != NULL) {
			materias[i] = other.materias[i]->clone();
		} else {
			materias[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& other) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other) {
		// Delete existing resources
		for (int i = 0; i < 4; ++i) {
			delete materias[i];
		}

		// Copy data from the other object
		name = other.name;
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

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		delete materias[i];
	}
}

void Character::learnMateria(AMateria*) {

}

AMateria* Character::createMateria(std::string const & type) {

}
