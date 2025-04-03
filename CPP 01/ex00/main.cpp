#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Marc");
	zombie->announce();
	randomChump("Un zombi cualquiera");
	delete(zombie);
}