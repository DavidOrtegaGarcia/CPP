#include "Animal.hpp"

Animal::Animal() : type("Default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal type constructor called" << std::endl;
	this->type = type; 
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
		this->type = other.type;
	return (*this);
}


std::string Animal::getType() const
{
	return(type);
}

void Animal::makeSound() const
{
	std::cout << "Default sound" << std::endl;
}