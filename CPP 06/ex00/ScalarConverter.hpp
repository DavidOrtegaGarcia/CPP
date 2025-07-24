#pragma once

#define IS_CHAR		1
#define IS_INT		2
#define IS_FLOAT 	3
#define IS_DOUBLE	4 


#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator = (const ScalarConverter &other);
	public:
		static void convert(std::string s);
	
};