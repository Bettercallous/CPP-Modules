#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " has been constructed" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
    this->name = other.name ;
    this->hitPoints = other.hitPoints ;
    this->energyPoints = other.energyPoints ;
    this->attackDamage = other.attackDamage ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
    this->name = other.name ;
    this->hitPoints = other.hitPoints ;
    this->energyPoints = other.energyPoints ;
    this->attackDamage = other.attackDamage ;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " has been destroyed !" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
