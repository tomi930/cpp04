#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {
    protected:
        std::string type;
    public:
        AAnimal(void);
        virtual ~AAnimal(void);
        AAnimal(const AAnimal & other);
        AAnimal &operator =(const AAnimal & other);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif
