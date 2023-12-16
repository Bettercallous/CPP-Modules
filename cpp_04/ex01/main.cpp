#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "---------------------------------" << std::endl;
	const Animal* a = new Dog();
	const Animal* b = new Cat();
	std::cout << "---------------------------------" << std::endl;
	delete a;
	delete b;
	std::cout << "---------------------------------" << std::endl;

	Animal *animals[6];

	for (int i = 0; i < 3; i++) {
		animals[i] = new Cat();
	}
	std::cout << "---------------------------------" << std::endl;
	for (int i = 3; i < 6; i++) {
		animals[i] = new Dog();
	}

	std::cout << "---------------------------------" << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cout << animals[i]->getType() << " says ";
		animals[i]->makeSound();
	}
	std::cout << "---------------------------------" << std::endl;

	for (int i = 0; i < 6; i++) {
		delete animals[i];
	}

	// std::cout << "----------Deep copy test----------" << std::endl;

	// Dog basic;
	// {
	// 	Dog tmp = basic;
	// }
	// basic.getBrain()->printIdeas();

	// std::cout << "---------------------------------" << std::endl;
	return 0;
}
