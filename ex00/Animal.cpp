#include "Animal.hpp"

Animal::Animal(void){
    type = "no-type";
};

Animal::~Animal(void){
}

Animal::Animal(const Animal & other){
    *this = other;
}

Animal &Animal::operator =(const Animal & other){
    type = other.type;
    return (*this);
}