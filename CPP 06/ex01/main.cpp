#include "Serializer.hpp"

int main(void)
{
	uintptr_t var;
	Data tdata;

	var = Serializer::serialize(&tdata);
	std::cout << "Data no serializer: " << &tdata << std::endl; 
	std::cout << "uintptr_t: " << var << std::endl;
	std::cout << "Data serializer: " << Serializer::deserialize(var) << std::endl; 
}