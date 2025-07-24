#include "Serializer.hpp"

//ORTHODOX CANONICAL FORM
Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = other;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;	
}

Serializer &Serializer::operator = (const Serializer &other)
{
	if (this != &other){} // If the class gets attributes equalize them inside the if
	return(*this);
}

//MEMBER FUNCTIONS
uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}