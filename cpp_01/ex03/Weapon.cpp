#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string str) {
	type = str;
}

const std::string& Weapon::getType() {
	const std::string& ref = type;
	return (ref);
}

void Weapon::setType(std::string type) {
	this->type = type;
}