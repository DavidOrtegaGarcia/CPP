#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern &other){ *this = other;}
Intern::~Intern(){}
Intern &Intern::operator = (const Intern &other)
{	
	(void)other;
	return(*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation" ,"robotomy request", "presidential pardon"};
	int i = 0;

	for (i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			break;
	}

	AForm *form;
	switch(i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw InvalidFormException();
	}
	return(form);
}

//EXCEPTIONS
const char* Intern::InvalidFormException::what() const throw()
{
	return("Invalid form");
}