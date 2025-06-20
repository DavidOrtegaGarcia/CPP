#include "PresidentialPardonForm.hpp"

//ORTHODOX CANONICAL FORM
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PPF", 25, 5),
																	_target(target)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): 
												AForm(other),_target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return(*this);
}

//GETTERS
std::string PresidentialPardonForm::getTarget() const
{
	return(_target);
}

//MEMBER FUNCTIONS

void PresidentialPardonForm::executeForm() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}