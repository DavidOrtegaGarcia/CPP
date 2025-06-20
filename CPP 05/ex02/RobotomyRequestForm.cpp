#include "RobotomyRequestForm.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime> 

//ORTHODOX CANONICAL FORM
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return(*this);
}

//GETTERS
std::string RobotomyRequestForm::getTarget() const
{
	return(_target);
}

//MEMBER FUNCTIONS
void RobotomyRequestForm::executeForm() const
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Brbrbrbr" << std::endl;
		sleep(1);
	}
	srand(time(0)); // Used to set the starting point for generating random numbers. 
					//If not used, the sequence of numbers would be the same in every execution
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy to " << _target << " has failed" << std::endl;	
}