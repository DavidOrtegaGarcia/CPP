#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal *meta[100]; //Const para que no podamos modificar los atributos de los objetos

	for(int i = 0; i < 100; i++)
	{
		if (i < 50)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}

	for(int i = 0; i < 100; i++)
	{
		if (i < 50)
			delete (meta[i]);
		else
			delete (meta[i]);
	}
	
	std::cout << std::endl;
	delete j;//should not create a leak
	delete i;
	return 0;
}