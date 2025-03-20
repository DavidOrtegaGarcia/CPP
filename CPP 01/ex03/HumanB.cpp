#include "HumanB.hpp"

// Constructor con lista de inizializacion 
// Es quivalente a poner dentro del contructor
//(_name = name y _weapon = NULL)
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){} 
HumanB::~HumanB(){}
void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}