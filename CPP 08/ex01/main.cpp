#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		sp.addNumber(6);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(100);	
	}
	catch(std:: exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Span sp2 = Span(10);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		sp2.addNumbers(v.begin(), v.end());
		sp2.printSpan();

		v.push_back(6);

		sp2.addNumbers(v.begin(), v.end());
		sp2.printSpan();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Span sp3 = Span(20000);
		for (int i = 0; i < 20000; i++)
			sp3.addNumber(i);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	

	return 0;
}
