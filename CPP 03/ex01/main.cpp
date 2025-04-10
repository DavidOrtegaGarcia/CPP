#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap ct1 = ClapTrap("David");
	ScavTrap st1 = ScavTrap("Laura");
	ScavTrap st2 = ScavTrap(st1);
	ScavTrap st3;

	st3 = st2;
	st3.beRepaired(1);
	st1.guardGate();
	for(int i = 0; i < 11; i++)
	{
		st1.attack("Test");
		st1.takeDamage(10);
	}
	st1.guardGate();
	ct1.attack("Test2");
}
