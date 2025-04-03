#include "FragTrap.hpp"

//----Constructors----
FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_name = "Default FragTrap";
	_hp = 100;
	_ep = 100;
	_attackDMG = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 100;
	_attackDMG = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_attackDMG = other._attackDMG;
	}
	return (*this);
}

//----Functions----
void FragTrap::highFivesGuys(void)
{
	if (_hp <= 0)
	std::cout << "FragTrap " << _name << " is dead" << std::endl;
	else if (_ep <= 0)
		std::cout << "FragTrap " << _name << " has no energy" << std::endl;
	else
{
	--_ep;
	std::cout << "FragTrap " << _name << " request a high five" << std::endl;
}
}