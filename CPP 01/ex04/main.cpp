#include <iostream>
#include <fstream>

void replace_line(std::string line, std::string s1,std::string s2, std::ofstream &dest)
{
	int i = 0;

	while (i < (int)line.length())
	{
		std::string substr = line.substr(i, s1.length());
		if (substr == s1)
		{
			dest << s2;
			i += s1.length();
		} 
		else
		{
			dest << line[i];
			i++;
		}
	}
}


int main(int argc, char *argv[])
{
	std::string	filename;
	std::string s1;
	std::string s2;
	std::ifstream org;
	std::ofstream dest;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);	
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	org.open(filename.c_str());
	if (!org.is_open())
	{
		std::cout << "Error: " << filename << " doesn't exist" << std::endl;
		return (1);
	}
	filename += ".replace";
	dest.open(filename.c_str(), std::ios::out);
	if (!dest.is_open())
	{
		std::cout << "Error: " << filename << " couldn't be opened" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(org, line)) 
		replace_line(line, s1, s2, dest);
	org.close();
	dest.close();
}

	