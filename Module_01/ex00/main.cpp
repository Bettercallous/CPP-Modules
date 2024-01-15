#include "Zombie.hpp"

int main()
{
	randomChump("Alberto");
	Zombie *zombie = newZombie("Juan");
	zombie->announce();
	delete zombie;
}