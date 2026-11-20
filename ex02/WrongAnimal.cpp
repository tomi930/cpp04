#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
    type = "no-type";
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & other){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator =(const WrongAnimal & other){
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

void WrongAnimal::makeSound(void) const{
    std::cout << "no sound made from WrongAnimal class" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return (type);
}
