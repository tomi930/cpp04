#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 4

int main()
{
    std::cout << "----- Subject test -----" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;
    }

    std::cout << std::endl << "----- Array of Animals (half Dogs, half Cats) -----" << std::endl;
    {
        const Animal* animals[ARRAY_SIZE];
        for (int k = 0; k < ARRAY_SIZE; k++)
        {
            if (k < ARRAY_SIZE / 2)
                animals[k] = new Dog();
            else
                animals[k] = new Cat();
        }
        for (int k = 0; k < ARRAY_SIZE; k++)
        {
            std::cout << animals[k]->getType() << ": ";
            animals[k]->makeSound();
        }
        for (int k = 0; k < ARRAY_SIZE; k++)
            delete animals[k];
    }

    std::cout << std::endl << "----- Deep copy: Dog copy constructor -----" << std::endl;
    {
        Dog original;
        original.setIdea(0, "chase the ball");
        Dog copy(original);
        original.setIdea(0, "eat the sofa");
        std::cout << "original idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "copy     idea[0]: " << copy.getIdea(0) << std::endl;
        if (copy.getIdea(0) == "chase the ball")
            std::cout << "OK: deep copy" << std::endl;
        else
            std::cout << "KO: shallow copy" << std::endl;
    }

    std::cout << std::endl << "----- Deep copy: Cat copy assignment operator -----" << std::endl;
    {
        Cat a;
        Cat b;
        a.setIdea(0, "sleep on the keyboard");
        b = a;
        a.setIdea(0, "knock the glass off the table");
        std::cout << "a idea[0]: " << a.getIdea(0) << std::endl;
        std::cout << "b idea[0]: " << b.getIdea(0) << std::endl;
        if (b.getIdea(0) == "sleep on the keyboard")
            std::cout << "OK: deep copy" << std::endl;
        else
            std::cout << "KO: shallow copy" << std::endl;
    }

    std::cout << std::endl << "----- Self assignment -----" << std::endl;
    {
        Cat c;
        c.setIdea(1, "stare at the wall");
        Cat &ref = c;
        c = ref;
        std::cout << "c idea[1]: " << c.getIdea(1) << std::endl;
    }

    std::cout << std::endl << "----- Out of range idea index -----" << std::endl;
    {
        Dog d;
        d.setIdea(100, "should be ignored");
        d.setIdea(-1, "should be ignored");
        std::cout << "idea[100]: \"" << d.getIdea(100) << "\"" << std::endl;
    }

    std::cout << std::endl << "----- WrongAnimal (from ex00) -----" << std::endl;
    {
        const WrongAnimal* wrongCat = new WrongCat();
        wrongCat->makeSound();
        delete wrongCat;
    }
    return 0;
}
