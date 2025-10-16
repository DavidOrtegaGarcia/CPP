#pragma once

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator = (const Intern &other);

		AForm *makeForm(std::string name, std::string target);

		class InvalidFormException : public std::exception
		{
			public:
				const char* what() const throw(); //throw() means that no excpetion will be thrown
		};
};