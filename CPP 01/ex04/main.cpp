#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{

	std::string	filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::ifstream org;
	std::ofstream dest;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return(1);
	}


}

	