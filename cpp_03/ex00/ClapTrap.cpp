#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	this->name = "ClapTrap";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string name) {
	std::cout << "Constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	this->name = other.name;
	this->attackDamage = other.attackDamage;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints <= 0)
		std::cout << ">> ClapTrap " << name << " has no energy left to attack <<" << std::endl;
	else if (hitPoints <= 0)
		std::cout << ">> ClapTrap " << name << " needs to be repaired <<" << std::endl;
	else {
		std::cout << ">> ClapTrap " << name << " attacks " << target << " causing "
				  << attackDamage << " points of damage ! <<" << std::endl;
		energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << ">> ClapTrap " << name << " has taken " << amount
			  << " points of damage ! <<" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints <= 0)
		std::cout << ">> ClapTrap " << name << " has no energy left to repair <<" << std::endl;
	else {
		hitPoints += amount;
		energyPoints--;
		std::cout << ">> ClapTrap " << name << " repaired " << amount
				  << " hit points ! <<" << std::endl;
	}
}
