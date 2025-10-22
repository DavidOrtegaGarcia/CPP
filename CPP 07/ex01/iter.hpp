#pragma once

#include <iostream>

template<typename T>
void print_array_value(T &data)
{
	std::cout << data << " ";
}

template<typename T>
void print_array_value(const T &data)
{
	std::cout << data << " ";
}

template<typename T>
void iter(T *array, const int length, void (*function)(T&))
{
	for(int i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

template<typename T>
void iter(const T *array, const int length, void (*function)(const T&))
{
	for(int i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

