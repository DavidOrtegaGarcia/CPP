#include "iter.hpp"

int main(void)
{
	char c[5] = {'1', '2', '3', '4', '5'};
	int i[5] = {1, 2, 3, 4, 5};
	float f[5] ={0.11, 0.12, 0.13, 0.14, 0.15};
	double d[5] ={0.16, 0.17, 0.18, 0.19, 0.2};

	iter(c, 5, print_array_value);
	std::cout << std::endl;
	iter(i, 5, print_array_value);
	std::cout << std::endl;
	iter(f, 5, print_array_value);
	std::cout << std::endl;
	iter(d, 5, print_array_value);
	std::cout << std::endl;
}