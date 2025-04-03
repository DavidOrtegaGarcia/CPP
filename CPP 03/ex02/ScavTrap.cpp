#include "ScavTrap.hpp"

//----Constructors----
ScavTrap::ScavTrap() 
{
	std::cout << "ScravTrap default constructor called" << std::endl;
	_name = "Default ScravTrap";
	_hp = 100;
	_ep = 50;
	_attackDMG = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScravTrap name constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 50;
	_attackDMG = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScravTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScravTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	std::cout << "ScravTrap copy assignment operator called" << std::endl;
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
void ScavTrap::attack(const std::string &target)
{
	if (_hp <= 0)
		std::cout << "ScravTrap " << _name << " is dead" << std::endl;
	else if (_ep <= 0)
		std::cout << "ScravTrap " << _name << " has no energy" << std::endl;
	else
	{
		_ep--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDMG << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (_hp <= 0)
		std::cout << "ScravTrap " << _name << " is dead" << std::endl;
	else if (_ep <= 0)
		std::cout << "ScravTrap " << _name << " has no energy" << std::endl;
	else
	{
		--_ep;
		std::cout << "ScravTrap " << _name << " is in gate keeper mode" << std::endl;
	}
}
