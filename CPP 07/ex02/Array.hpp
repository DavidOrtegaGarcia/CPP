#pragma once

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator = (const Array &other);

		unsigned int size() const;
		
		T &operator [] (unsigned int n);
};

#include "Array.tpp"