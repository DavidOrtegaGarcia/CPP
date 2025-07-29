#pragma once

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack &operator = (const MutantStack &other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

//IMPLEMENTATION
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other){}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack<T> &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return(*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return(this->c.begin());
} 

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return(this->c.end());
}



