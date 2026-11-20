#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "----- WrongAnimal tests -----" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;
    std::cout << std::endl << "----- Stack objects call their own makeSound -----" << std::endl;
    {
        Dog dog;
        Cat cat;
        WrongCat wcat;
        std::cout << dog.getType() << ": ";
        dog.makeSound();
        std::cout << cat.getType() << ": ";
        cat.makeSound();
        std::cout << wcat.getType() << " (called directly): ";
        wcat.makeSound();
    }

    std::cout << std::endl << "----- Copy constructor -----" << std::endl;
    {
        Dog original;
        Dog copy(original);
        std::cout << "copy type: " << copy.getType() << std::endl;
        copy.makeSound();
    }

    std::cout << std::endl << "----- Copy assignment operator -----" << std::endl;
    {
        Cat a;
        Cat b;
        b = a;
        std::cout << "b type: " << b.getType() << std::endl;
        b.makeSound();
    }

    std::cout << std::endl << "----- Array of Animal pointers -----" << std::endl;
    {
        const Animal* animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
        for (int k = 0; k < 4; k++)
        {
            std::cout << animals[k]->getType() << ": ";
            animals[k]->makeSound();
        }
        for (int k = 0; k < 4; k++)
            delete animals[k];
    }
    return 0;
}
