#pragma once

#include <iostream>

template<typename T>
void print_array_value(T data)
{
	std::cout << data << " ";
}

template<typename T>
void iter(T *array, int length, void (*function)(T))
{
	for(int i = 0; i < length; i++)
	{
		function(array[i]);
	}
}