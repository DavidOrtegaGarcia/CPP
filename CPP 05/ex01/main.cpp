#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "SET TOO LOW GRADE TO SIGN TEST:" << std::endl;
	try
	{
		Form test("Form1", 151, 100);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "SET TOO LOW GRADE TO EXECUTE TEST:" << std::endl;
	try
	{
		Form test("Form1", 100, 151);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "SET TOO HIGH GRADE TO SIGN TEST:" << std::endl;
	try
	{
		Form test("Form1", 0, 100);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "SET TOO HIGH GRADE TO EXECUTE TEST:" << std::endl;
	try
	{
		Form test("Form1", 100, 0);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TOO LOW TO SIGN GRADE TEST:" << std::endl;
	Form form1("Form1", 100, 120);
	Bureaucrat bur1("Juan", 101);
	std::cout << form1 << std::endl;
	bur1.signForm(form1);
	std::cout << form1 << std::endl;
	std::cout << std::endl;

	std::cout << "CORRECT SIGN GRADE TEST:" << std::endl;
	Form form2 = Form("Form2", 100, 120);
	Bureaucrat bur2 = Bureaucrat("David", 99);
	std::cout << form2 << std::endl;
	bur2.signForm(form2);
	std::cout << form2 << std::endl;
	std::cout << std::endl;

	std::cout << "TESTS FINISHED" << std::endl;
}