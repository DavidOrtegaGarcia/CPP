#include "Array.hpp"

//ORTHODOX CANONICAL FORM
template<typename T>
Array<T>::Array()
{
	_array = NULL;
	_size= 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_size= n;
}

template<typename T>
Array<T>::Array(const Array<T> &other)
{
	// Avoid using *this = other here because it would delete 
	// uninitialized memory and cause a SEGV.
	_size = other._size;
	_array = new T[_size];
	for(unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array; 
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return(*this);
}

//GETTERS
template<typename T>
unsigned int Array<T>::size() const
{
	return(_size);
}

//OPERATORS
template<typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("That position doesn't exist!!!");
	return(_array[n]);
} 
