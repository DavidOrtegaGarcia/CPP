#pragma once 

#include <iostream>
#include <vector>
#include <deque>
#include <cctype>
#include <cstdlib>
#include <climits>

void fillVec(std::vector<int> &vec, int argc, char *argv[]);
void convertVecToDeq(std::vector<int> &vec, std::deque<int> &deq);

template<typename T>
bool isSort(T &container)
{
	int size = container.size();

	for (int i = 1; i < size; i++)
	{
		if (container[i] < container[i - 1])
			return(false);
	}	
	return(true);
}

template<typename T>
void printContainer(T &container)
{
	int size = container.size();
	for (int i = 0; i < size; i++)
		std::cout << container[i] << ' ';
	std::cout << std::endl;
}

template<typename T>
void binary_insertion(T &container, int key, int low, int high)
{
	int mid;
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key >= container[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	container.insert(container.begin() + low, key);
}

//Insert the pendign numbres into main_chain in blocks defined by Jacobsthal numbers.
//for every block we insert the numbers from last to first for optimization
template<typename T>
void insertJacobsthalOrder(T &main_chain, T &pending)
{
	int size = pending.size();
	if (size == 0)
		return;
	binary_insertion(main_chain, pending[0], 0, main_chain.size() - 1);
	if (size == 1)
		return;
	binary_insertion(main_chain, pending[1], 0, main_chain.size() - 1);
	if (size == 2)
		return;
		
	int old_pos = 1;
	int current_pos = 3;

	while (old_pos < size - 1)
	{
		int block_end = current_pos;
		if (current_pos >= size)
			block_end = size - 1;
		for (int i = block_end ; i > old_pos; i--)
			binary_insertion(main_chain, pending[i], 0, main_chain.size() - 1);
		int next_pos = current_pos + 2 * old_pos; //Formula to get next Jacobsthal number 
		old_pos = current_pos;
		current_pos = next_pos; 
	}
}

//MERGE INSERTION SORT V2
template<typename T>
void merge_insertion_sort(T &container)
{
	T main_chain;
	T pending;
	
	int size = container.size();
	if (size < 2)
		return;
	for (int i = 0; i + 1 < size; i += 2)
	{
		if (container[i] >= container[i + 1])
		{
			main_chain.push_back(container[i]);
			pending.push_back(container[i + 1]);
		}
		else
		{
			main_chain.push_back(container[i + 1]);
			pending.push_back(container[i]);
		}
	}
	if (size % 2 != 0)
	main_chain.push_back(container[size - 1]);
	
	merge_insertion_sort(main_chain);
	
	insertJacobsthalOrder(main_chain, pending);
	std::swap(container, main_chain);
}

//MERGE INSERTION SORT V1
/* 
template<typename T>
void merge_insertion_sort(T &container)
{
	T aux;

	if (container.size() < 2)
		return;
	for (size_t i = 0; i < container.size(); i++)
	{
		if (i + 1 == container.size())
			break;
		if (container[i] >= container[i + 1])
		{
			aux.push_back(container[i + 1]);
			conatiner.erase(container[i + 1]);
		}
		else
		{
			aux.push_back(container[i]);
			conatiner.erase(container[i]);
		}
	}
	merge_insertion_sort(container);
	for (size_t i = 0; i < aux.size(); i++)
		binary_insertion(main_chain, pending[i], 0, main_chain.size() - 1);
}
*/