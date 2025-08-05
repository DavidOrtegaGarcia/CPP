#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char *argv[])
{
	std::vector<int> vec;
	std::deque<int> deq;

	if (argc < 3)
	{
		std::cerr << "PmergeMe needs at least 3 arguments to work" << std::endl;
		return(-1);
	}
	try
	{
		fillVec(vec, argc, argv);
		convertVecToDeq(vec, deq);

		std::cout << "Before: ";
		printContainer(vec);

		clock_t startVec = clock();
		merge_insertion_sort(vec);
		clock_t endVec = clock();

		std::cout << "After: ";
		printContainer(vec);

		clock_t startDeq = clock();
		merge_insertion_sort(deq);
		clock_t endDeq = clock();
		
		clock_t timeVec = (static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC) * 1000000;
		clock_t timeDeq = (static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC) * 1000000;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : ";
		std::cout << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : ";
		std::cout << timeDeq << " us" << std::endl;

	} 
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
