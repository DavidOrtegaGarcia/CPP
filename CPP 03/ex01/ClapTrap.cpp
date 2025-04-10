#include "ClapTrap.hpp"

//----Constructors----

ClapTrap::ClapTrap() : _name("Default Clap"), _hp(10), _ep(10), _attackDMG(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _attackDMG(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
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
void ClapTrap::attack(const std::string &target)
{
	if (_hp <= 0)
		std::cout << _name << " is dead" << std::endl;
	else if (_ep <= 0)
		std::cout << _name << " has no energy" << std::endl;
	else
	{
		_ep--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDMG << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
		std::cout << _name << " is dead" << std::endl;
	else
	{
		if (amount > _hp)
			_hp = 0;
		else
			_hp -= amount;
		std::cout << "ClapTrap " << _name << " has lost " << amount << "HP. He has now " << _hp << " HP" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
		std::cout << _name << " is dead" << std::endl;
	else if (_ep <= 0)
		std::cout << _name << " has no energy" << std::endl;
	else
	{
		_hp += amount;
		_ep--;
		std::cout << "ClapTrap " << _name << " gets repared, getting " << amount << " HP. He has now " << _hp << " HP" << std::endl;
	}
}
