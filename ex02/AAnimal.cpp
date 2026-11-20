#include "AAnimal.hpp"

AAnimal::AAnimal(void){
    type = "no-type";
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal(void){
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal & other){
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator =(const AAnimal & other){
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

std::string AAnimal::getType(void) const{
    return (type);
}
