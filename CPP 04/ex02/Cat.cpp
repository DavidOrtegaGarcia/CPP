#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;\
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete(_brain);
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (_brain)
			delete(_brain);
		_brain = new Brain(*other._brain);
	}
	return (*this);
}


void Cat::makeSound() const
{
	std::cout << "Miau miau" << std::endl;
}
