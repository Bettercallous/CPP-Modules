#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(const std::string name) {
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	this->name = other.name;
	this->attackDamage = other.attackDamage;
	this->hitPoints = other.hitPoints;
}

void ClapTrap::attack(const std::string& target) {
	
}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}
