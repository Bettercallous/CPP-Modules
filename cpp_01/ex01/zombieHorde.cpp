#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		new (&zombies[i]) Zombie(name); // constructs a Zombie object at the memory address of zombies[i]
	}
	return zombies;
}