#include "Animal.hpp"

Animal::Animal() : _type("Default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator = (const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}


std::string Animal::getType() const
{
	return(_type);
}

void Animal::makeSound() const
{
	std::cout << "Default sound" << std::endl;
}