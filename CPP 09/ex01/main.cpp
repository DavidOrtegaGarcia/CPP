#include "RPN.hpp"

int main(int argc, char *argv[])
{
	RPN rpn;
	if (argc != 2)
	{
		std::cerr << "RPN needs 1 parameter exactly!!!" << std::endl;
		return 1;
	}
	try
	{
		rpn.makeOperations(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << std::endl;
	}

}