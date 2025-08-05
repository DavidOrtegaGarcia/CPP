#include "PmergeMe.hpp"

bool isValidNum(char *arg)
{

	size_t i = 0;
	long num = 0;

	for (; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
			return(false);
		num *= 10;
		num += arg[i] - '0';
		if (num > INT_MAX)
			return(false);
	}
	if (i == 0)
		return(false);
	return(true);
}

void fillVec(std::vector<int> &vec, int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (!isValidNum(argv[i]))
			throw std::logic_error("Invalid Input");
		vec.push_back(atoi(argv[i]));
	}
}

void convertVecToDeq(std::vector<int> &vec, std::deque<int> &deq)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
		deq.push_back(vec[i]);

}

