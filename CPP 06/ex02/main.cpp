#include "Base.hpp"
#include <cstdlib>
#include <ctime>

void identify(Base& p)
{
	try 
	{
		A &ref = dynamic_cast<A&>(p);
		(void)ref;
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e){}

	try
	{
		B &ref = dynamic_cast<B&>(p);
		(void)ref;
		std::cout << "B" << std::endl;
	}
	catch(std::exception &e){}
	
	try
	{
		C &ref = dynamic_cast<C&>(p);
		(void)ref;
		std::cout << "C" << std::endl;
	}
	catch(std::exception &e){}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;

}
Base *getRandomChild()
{
	Base *obj;

	srand(time(NULL));
	switch(rand() % 3)
	{
		case 0:
			obj = new A();
			//std::cout << "Object is A" << std::endl;
			break;
		case 1:
			obj = new B();
			//std::cout << "object is B" << std::endl;
			break;
		case 2:
			obj = new C();
			//std::cout << "Object is C" << std::endl;
			break;
	}
	return (obj);
}

int main(void)
{
	Base *obj;

	obj = getRandomChild(); 
	identify(obj);
	identify(*obj);

	delete(obj);
}