#include "ScavTrap.hpp"

//----Constructors----
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "Default ScavTrap";
	_hp = 100;
	_ep = 50;
	_attackDMG = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	_hp = 100;
	_ep = 50;
	_attackDMG = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

//----Functions----
void ScavTrap::attack(const std::string &target)
{
	if (_hp <= 0)
		std::cout << "ScavTrap " << _name << " is dead" << std::endl;
	else if (_ep <= 0)
		std::cout << "ScavTrap " << _name << " has no energy" << std::endl;
	else
	{
		_ep--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDMG << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (_hp <= 0)
		std::cout << "ScavTrap " << _name << " is dead" << std::endl;
	else if (_ep <= 0)
		std::cout << "ScavTrap " << _name << " has no energy" << std::endl;
	else
	{
		--_ep;
		std::cout << "ScavTrap " << _name << " is in gate keeper mode" << std::endl;
	}
}
