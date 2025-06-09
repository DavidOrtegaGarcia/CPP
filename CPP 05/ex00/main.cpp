#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "SET TOO LOW GRADE TEST:" << std::endl;
	try
	{
		Bureaucrat test("Juan", 151);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "SET TOO HIGH GRADE TEST:" << std::endl;
	try
	{
		Bureaucrat test("Juan", 0);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "INCREMENT GRADE TEST:" << std::endl;
	try
	{
		Bureaucrat test("Juan", 2);
		std::cout << test << std::endl;
		test.incrementGrade();
		std::cout << test << std::endl;
		test.incrementGrade();
		std::cout << test << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "DECREMENT GRADE TEST:" << std::endl;
	try
	{
		Bureaucrat test("Juan", 149);
		std::cout << test << std::endl;
		test.decrementGrade();
		std::cout << test << std::endl;
		test.decrementGrade();
		std::cout << test << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "MODIFICATIONS WITH OBJECT OUTSIDE THE TRY TEST:" << std::endl;
	Bureaucrat test("Juan", 149); // The changes inside the try will remain even if an exception is thrown
	try
	{
		std::cout << test << std::endl;
		test.decrementGrade();
		std::cout << test << std::endl;
		test.decrementGrade();
		std::cout << test << std::endl;
		
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "CHEKING GRADE OUTSIDE THE TRY:\n" << test << std::endl;
}