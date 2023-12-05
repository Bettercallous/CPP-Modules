#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints <= 0)
		std::cout << ">> ScavTrap " << name << " has no energy left to attack <<" << std::endl;
	else if (hitPoints <= 0)
		std::cout << ">> ScavTrap " << name << " needs to be repaired <<" << std::endl;
	else {
		std::cout << ">> ScavTrap " << name << " attacks " << target << " causing "
				  << attackDamage <<  " points of damage ! <<" << std::endl;
		energyPoints--;
	}
}

void ScavTrap::guardGate() {
	std::cout << ">>> ScavTrap " << name << " is now in Gate keeper mode <<<" << std::endl;
}
