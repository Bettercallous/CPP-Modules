#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name) {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}