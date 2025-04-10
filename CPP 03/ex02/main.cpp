#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap ct1 = ClapTrap("David");
	ScavTrap st1 = ScavTrap("Laura");
	FragTrap ft1 = FragTrap("Infernape");

	
	ft1.highFivesGuys();
	for(int i = 0; i < 11; i++)
	{
		ft1.attack("Test");
		ft1.takeDamage(10);
	}
	ft1.highFivesGuys();
	st1.attack("Test2");
	ct1.attack("Test3");
	
}
