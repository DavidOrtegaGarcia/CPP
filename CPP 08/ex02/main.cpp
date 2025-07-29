#include "MutantStack.hpp"
#include <list>
#include <algorithm>


int main()
{
	MutantStack<int> mstack;

	std::cout << "MutantStack tests" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "First element: " << mstack.top() << std::endl; //Prints de first value
	mstack.pop(); 
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Print container:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	/*list main*/
	std::cout << std::endl << "Same tests with std::list" << std::endl;
	std::list<int> ml;

	ml.push_back(17);
	ml.push_back(5);
	std::cout << "First element: " << ml.front() << std::endl; //Prints de first value
	ml.pop_front();
	std::cout << "Size: " << ml.size() << std::endl;
	
	ml.push_back(3);
	ml.push_back(5);
	ml.push_back(737);
	//[...]
	ml.push_back(0);
	std::list<int>::iterator lit = ml.begin();
	std::list<int>::iterator lite = ml.end();
	++lit;
	--lit;
	std::cout << "Print container:" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	return 0;
}
