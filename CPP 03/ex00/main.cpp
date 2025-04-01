#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct1 = ClapTrap("David");
	ClapTrap ct2 = ClapTrap("Juan");
	ClapTrap ct3 = ClapTrap(ct1);

	ct3 = ct1;

	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackDMG());
	ct2.beRepaired(ct1.getAttackDMG());

}
