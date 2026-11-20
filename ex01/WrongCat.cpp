#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal(){
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat(void){
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other){
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator =(const WrongCat & other){
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

void WrongCat::makeSound(void) const{
    std::cout << "Meowwww!" << std::endl;
}
