#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct1 = ClapTrap("David");
	ClapTrap ct2 = ClapTrap("Juan");
	ClapTrap ct3 = ClapTrap(ct1);

	ct3 = ct1;

	for(int i = 0; i < 12; i++)
	{
		ct1.attack("Test");
	}
	ct1.beRepaired(1);
	for(int i = 0; i < 6; i++)
	{
		ct1.takeDamage(2);
	}
	ct2.takeDamage(1);
	ct2.beRepaired(1);

}
