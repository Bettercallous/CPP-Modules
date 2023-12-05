#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (energyPoints <= 0)
		std::cout << "FragTrap " << name << " has no energy left to attack" << std::endl;
	else if (hitPoints <= 0)
		std::cout << "FragTrap " << name << " needs to be repaired" << std::endl;
	else {
		std::cout << "FragTrap " << name << " attacks " << target << " causing "
				  << attackDamage <<  " points of damage !" << std::endl;
		energyPoints--;
	}
}

void FragTrap::highFivesGuys(void) {
    std::cout << "!!! HIGH FIVE !!!" << std::endl;
}