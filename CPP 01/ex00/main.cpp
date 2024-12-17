#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Marc");
	zombie->announce();
	randomChump("Un zombie cualquiera");
	delete(zombie);
}