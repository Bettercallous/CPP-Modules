#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "---------------------------------" << std::endl;
    const Animal* a = new Dog();
    const Animal* b = new Cat();
    std::cout << "---------------------------------" << std::endl;
    delete a; //should not create a leak
    delete b;
    std::cout << "---------------------------------" << std::endl;

    Animal *animals = new Animal[10];
    std::cout << "---------------------------------" << std::endl;

    for (int i = 0; i < 5; i++) {
        new (&animals[i]) Cat();
    }
    std::cout << "---------------------------------" << std::endl;
    for (int i = 5; i < 10; i++) {
        new (&animals[i]) Dog();
    }

    std::cout << "---------------------------------" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << animals[i].getType() << " " << i + 1 << " says ";
        animals[i].makeSound(); 
    }
    std::cout << "---------------------------------" << std::endl;

    for (int i = 0; i < 10; i++) {
        animals[i].~Animal();
    }

    delete[] animals;

    return 0;
}
