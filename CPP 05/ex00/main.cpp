#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "SET TOO LOW GARDE TEST:" << std::endl;
	try
	{
		Bureaucrat test1("Juan", 151);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "SET TOO HIGH GARDE TEST:" << std::endl;
	try
	{
		Bureaucrat test1("Juan", 0);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "INCREMENT GARDE TEST:" << std::endl;
	try
	{
		Bureaucrat test1("Juan", 2);
		std::cout << test1 << std::endl;
		test1.incrementGrade();
		std::cout << test1 << std::endl;
		test1.incrementGrade();
		std::cout << test1 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "DECREMENT GARDE TEST:" << std::endl;
	try
	{
		Bureaucrat test1("Juan", 149);
		std::cout << test1 << std::endl;
		test1.decrementGrade();
		std::cout << test1 << std::endl;
		test1.decrementGrade();
		std::cout << test1 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "MODIFICATIONS WITH OBJECT OUTSIDE THE TRY TEST:" << std::endl;
	Bureaucrat test1("Juan", 149); // The changes inside the try will remain even if an exception is thrown
	try
	{
		std::cout << test1 << std::endl;
		test1.decrementGrade();
		std::cout << test1 << std::endl;
		test1.decrementGrade();
		std::cout << test1 << std::endl;
		
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "CHEKING GRADE OUTSIDE THE TRY:\n" << test1 << std::endl;
}