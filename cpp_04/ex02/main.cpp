#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "---------------------------------" << std::endl;
    const AAnimal* a = new Dog();
    const AAnimal* b = new Cat();
    std::cout << "---------------------------------" << std::endl;
    delete a;
    delete b;
    std::cout << "---------------------------------" << std::endl;

    AAnimal *animals[10];

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

    // std::cout << "----------Deep copy test----------" << std::endl;

    // AAnimal* _dog = new Dog();
    // AAnimal* _cat = new Cat();

    // std::cout << "_dog type: " << _dog->getType() << std::endl ;
    // std::cout << "_cat type: " << _cat->getType() << std::endl ;
    // *_dog = *_cat;
    // // _dog->setType("something");
    // std::cout << "_dog type: " << _dog->getType() << std::endl ;
    // std::cout << "_cat type: " << _cat->getType() << std::endl ;

    // delete _cat;
    // delete _dog;
    std::cout << "---------------------------------" << std::endl;

    return 0;
}
