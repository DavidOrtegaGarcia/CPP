#include  "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> v;
	std::vector<int>::iterator it;
	
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);

	it = easyfind(v, 3); 
	std::cout << *it << std::endl;

	try
	{
		it = easyfind(v, 10); 
		std::cout << *it << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}