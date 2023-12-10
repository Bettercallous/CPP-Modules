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
    delete a;
    delete b;
    std::cout << "---------------------------------" << std::endl;

    Animal **animals = new Animal*[10];

    for (int i = 0; i < 5; i++) {
        animals[i] = new Cat();
    }
    std::cout << "---------------------------------" << std::endl;
    for (int i = 5; i < 10; i++) {
        animals[i] = new Dog();
    }

    std::cout << "---------------------------------" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << animals[i]->getType() << " " << i + 1 << " says ";
        animals[i]->makeSound(); 
    }
    std::cout << "---------------------------------" << std::endl;

    for (int i = 0; i < 10; i++) {
        delete animals[i];
    }

    delete[] animals;

    std::cout << "---------Deep copy test---------" << std::endl;

    Animal* _dog = new Dog();
    Animal* _cat = new Cat();

    std::cout << "_dog type: " << _dog->getType() << std::endl ;
    std::cout << "_cat type: " << _cat->getType() << std::endl ;
    *_dog = *_cat;
    _dog->setType("something");
    std::cout << "_dog type: " << _dog->getType() << std::endl ;
    std::cout << "_cat type: " << _cat->getType() << std::endl ;

    std::cout << "---------------------------------" << std::endl;

    return 0;
}
