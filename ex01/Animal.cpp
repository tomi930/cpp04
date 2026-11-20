#include "Animal.hpp"

Animal::Animal(void){
    type = "no-type";
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal(void){
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal & other){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator =(const Animal & other){
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

void Animal::makeSound(void) const{
    std::cout << "no sound made from animal class" << std::endl;
}

std::string Animal::getType(void) const{
    return (type);
}
