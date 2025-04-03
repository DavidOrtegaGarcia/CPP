#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap ct1 = ClapTrap("David");
	ScavTrap st1 = ScavTrap("Laura");

	st1.guardGate();
	for(int i = 0; i < 11; i++)
	{
		st1.attack("Test");
		st1.takeDamage(10);
	}
	st1.guardGate();
}
