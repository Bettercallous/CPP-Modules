#include "Character.hpp"

Character::Character() {
	// std::cout << "Character default constructor called" << std::endl;
	_name = "Unnamed";
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	// std::cout << "Character constructor called" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	// std::cout << "Character copy constructor called" << std::endl;
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	// std::cout << "Character copy assignment operator called" << std::endl;
	_name = other._name;
	if (this != &other) {

		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = NULL;
		}

		for (int i = 0; i < 4; i++) {
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) 
		return ;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	ICharacter *p = &target;
	if (!p)
		return;
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	}
}