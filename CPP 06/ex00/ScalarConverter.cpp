#include "ScalarConverter.hpp"
#include <climits>
#include <sstream>
#include <cstdlib>

//ORTHODOX CANONICAL FORM
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}


//CONVERT FUNCTIONS
void convertChar(char c)
{
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
	}
}


bool checkIntOverflow(std::string &s)
{
	std::ostringstream oss;
	oss << INT_MAX;
	std::string max_int = oss.str(); // Convert int to string

	if (s[0] == '-')
		return (false);
	s.erase(0, s.find_first_not_of('0')); // Delete all leading zeros, 
										  // including their position in the string
	if (s.length() > max_int.length())
		return(true);
	if (s.length() == max_int.length() && s > max_int)
		return(true);
	return(false);
}

bool checkIntUnderflow(std::string &s)
{
	std::ostringstream oss;
	oss << INT_MIN;
	std::string min_int = oss.str(); // Convert int to string

	if (s[0] != '-')
		return (false);
	s.erase(1, s.find_first_not_of('0', 1) -1); // Delete all leading zeros after the -, including their position in the string.
												// We start eraisng from pos 1 of the string and we also search from pos 1 to avoid the -.
												// find_first_not_of returns the index of the first number that is not a 0 starting from position 1 (doesn't check the - in pos 0).
												// This means that -0001234 wil return 4 and we need to decrement by 1 to match the number of leading zeros
												//            pos: 01234567 		
	if (s.length() > min_int.length())
		return(true);
	if (s.length() == min_int.length() && s > min_int)
		return(true);
	return(false);
}

void convertInt(std::string s)
{
	int integer = atoi(s.c_str());
	if (checkIntOverflow(s))
		std::cout << "Int overflows" << std::endl;
	else if (checkIntUnderflow(s))
		std::cout << "Int underflows" << std::endl;
	else
	{
		if (!isascii(integer))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(integer))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
		std::cout << "int: " << integer << std::endl;
		std::cout << "float: " << static_cast<float>(integer) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(integer) << ".0" << std::endl;
	}
}

void floatSpecialCase(std::string s)
{
	if (s == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << s << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	} 
	else if (s == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << s << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	}
	else 
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << s << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

void convertFloat(std::string s)
{
	float flt = atof(s.c_str());

	if (s == "-inff" || s == "+inff" || s == "nanf")
	{
		floatSpecialCase(s);
		return;
	}
	if (static_cast<long>(flt) > INT_MAX || static_cast<long>(flt) < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else if (flt == static_cast<int>(flt) && isascii(static_cast<int>(flt))) // if don't have decimals and is ascii
	{
		if (!isprint(static_cast<int>(flt)))
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(flt) << std::endl;
			std::cout << "float: " << flt << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(flt) << ".0" << std::endl;
		}
		else
		{
			std::cout << "char: '" << static_cast<char>(flt) << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(flt)<< std::endl;
			std::cout << "float: " << flt << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(flt) << ".0" << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << static_cast<int>(flt) << std::endl;
		std::cout << "float: " << flt << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(flt) << std::endl;
	}
}

void doubleSpecialCase(std::string s)
{
	if (s == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << s << std::endl;
	} 
	else if (s == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << s << std::endl;
	}
	else 
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << s << std::endl;
	}
}

void convertDouble(std::string s)
{
	double dbl = atof(s.c_str());

	if (s == "-inf" || s == "+inf" || s == "nan")
	{
		doubleSpecialCase(s);
		return;
	}
	if (static_cast<long>(dbl) > INT_MAX || static_cast<long>(dbl) < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else if (dbl == static_cast<int>(dbl) && isascii(static_cast<int>(dbl))) // if don't have decimals and is ascii
	{
		if (!isprint(static_cast<int>(dbl)))
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(dbl) << std::endl;
			std::cout << "float: " << static_cast<float>(dbl) << ".0f" << std::endl;
			std::cout << "double: " << dbl << ".0" << std::endl;
		}
		else
		{
			std::cout << "char: '" << static_cast<char>(dbl) << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(dbl)<< std::endl;
			std::cout << "float: " << static_cast<float>(dbl) << ".0f" << std::endl;
			std::cout << "double: " << dbl << ".0" << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << static_cast<int>(dbl) << std::endl;
		std::cout << "float: " << static_cast<float>(dbl) << "f" << std::endl;
		std::cout << "double: " << dbl << std::endl;
	}
}
//CHECK TYPE FUNCTIONS
bool isInt(std::string s)
{
	size_t i = 0;
	
	if (s[0] == '-')
		i++;
	while(i < s.length())
	{
		if(!isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isFloat(std::string s)
{
	size_t i = 0;
	int dot_count = 0;
	
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return (true);
	if (s[s.length() - 1] != 'f' && s[s.length() - 1] != 'F')
		return (false);
	if (s[0] == '-')
		i++;
	while (i < s.length() -1)
	{
		if (s[i] == '.')
		{	
			dot_count++;
			if (dot_count > 1)
				return (false);
		}
		if (!isdigit(s[i]) && s[i] != '.')
			return (false);
		i++;
	}
	return(true);
}

bool isDouble(std::string s)
{
	size_t i = 0;
	int dot_count = 0;
	
	if (s == "-inf" || s == "+inf" || s == "nan")
		return (true);
	if (s[0] == '-')
		i++;
	while (i < s.length())
	{
		if (s[i] == '.')
		{	
			dot_count++;
			if (dot_count > 1)
				return (false);
		}
		if (!isdigit(s[i]) && s[i] != '.')
			return (false);
		i++;
	}
	return(true);
}

int checkType(std::string s)
{
	if (s.length() == 1 && isprint(s[0]) && !isdigit(s[0]))
		return (IS_CHAR);
	if (isInt(s))
		return (IS_INT);
	if (isFloat(s))
		return (IS_FLOAT);
	if(isDouble(s))
		return (IS_DOUBLE);
	return(-1);
}

//MEMBER FUNCTIONS
void ScalarConverter::convert(std::string s)
{
	switch(checkType(s))
	{
		case IS_CHAR:
			convertChar(s[0]);
			break;
		case IS_INT:
			convertInt(s);
			break;
		case IS_FLOAT:
			convertFloat(s);
			break;
		case IS_DOUBLE:
			convertDouble(s);
			break;
		default:
			std::cout << "INVALID ARGUMENT, TRY AGAIN" << std::endl;
	}
}