#include "Brain.hpp"

Brain::Brain(){}

Brain::Brain(const Brain &other)
{
	*this = other;
}

Brain::~Brain(){}

Brain &Brain::operator = (const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}
