#include "Character.hpp"

Character::Character() {
	// std::cout << "Character default constructor called" << std::endl;
	this->name = "";
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(std::string name) {
	// std::cout << "Character constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(const Character& other) {
	// std::cout << "Character copy constructor called" << std::endl;
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
	// std::cout << "Character copy assignment operator called" << std::endl;
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

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (!m) 
		return ;
	for (int i = 0; i < 3; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = m->clone();
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		delete materias[idx];
		materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	ICharacter *p = &target;
	if (!p)
		return;
	if (idx >= 0 && idx < 4 && materias[idx] != NULL) {
		materias[idx]->use(target);
	}
}