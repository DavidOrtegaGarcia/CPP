#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") 
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog type constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete (_brain);
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (_brain)
			delete (_brain);
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}