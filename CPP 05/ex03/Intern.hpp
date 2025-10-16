#pragma once

#include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator = (const Intern &other);

		AForm *makeForm(std::string name, std::string target);
};