#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "--- Animal test with virtual member function ---" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " says ";
	j->makeSound(); // will output the cat sound!
	std::cout << i->getType() << " says ";
	i->makeSound();
	std::cout << meta->getType() << " says ";
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "--- wrong animal test (non virtual member function) ---" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " says ";
	wrong->makeSound();
	delete wrong;
	std::cout << "-------------------------------------------------------" << std::endl;

	return 0;
}
