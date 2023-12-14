#include "Character.hpp"

Character::Character() {
	// std::cout << "Character default constructor called" << std::endl;
	this->name = "Unnamed";
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	// std::cout << "Character constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	// std::cout << "Character copy constructor called" << std::endl;
	this->name = other.name;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	// std::cout << "Character copy assignment operator called" << std::endl;
	this->name = other.name;
	if (this != &other) {

		for (int i = 0; i < 4; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = NULL;
		}

		for (int i = 0; i < 4; i++) {
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if (!m) 
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	ICharacter *p = &target;
	if (!p)
		return;
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx]->use(target);
	}
}