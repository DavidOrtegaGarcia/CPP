#include "ClapTrap.hpp"

//----Constructors----
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _attackDMG(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other.getName();
		_hp = other.getHP();
		_ep = other.getEP();
		_attackDMG = other.getAttackDMG();
	}

	return (*this);
}

//----Getters & setters----
std::string ClapTrap::getName() const
{
	return(_name);
}
int ClapTrap::getHP() const 
{
	return(_hp);
}
int	ClapTrap::getEP() const 
{
	return(_ep);
}
int	ClapTrap::getAttackDMG() const 
{
	return(_attackDMG);
}
void	ClapTrap::setName(std::string name)
{
	_name = name;
}
void	ClapTrap::setHP(int hp)
{
	_hp = hp;
}
void	ClapTrap::setEP(int ep)
{
	_ep = ep;
}
void	ClapTrap::setAttackDMG(int attack)
{
	_attackDMG = attack;
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
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDMG << " points of damage!" << std::endl;
		_ep--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
		std::cout << _name << " is dead" << std::endl;
	else
	{
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
		std::cout << "ClapTrap " << _name << " gets repared, getting " << amount << " HP. He has now " << _hp << " HP" << std::endl;
		_ep--;
	}
}
