#include "Span.hpp"

//ORTHODOX CANONICAL FORM
Span::Span() : _max_size(0){}
Span::Span(unsigned int N) : _max_size(N){}

Span::Span(const Span &other) : _nums(other._nums), _max_size(other._max_size){}

Span::~Span(){}

Span &Span::operator = (const Span &other)
{
	if (this != &other)
	{
		_nums = other._nums;
		_max_size = other._max_size;
	}
	return(*this);
}

//MEMBER FUNCTIONS
void Span::addNumber(int num)
{
	if (_nums.size() >= _max_size)
		throw std::length_error("Span has reached his maximum capacity");
	_nums.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	int num_of_numbers;

	num_of_numbers = std::distance(start, end);
	if (num_of_numbers + _nums.size() > _max_size)
		throw (std::length_error("Span has not enough capacity"));
	_nums.insert(_nums.end(), start, end);
}


// The next 2 functions can be implemented whitout iterators 
// but i wanted to practice using them
int Span::shortestSpan()
{
	std::vector<int> tmp;
	std::vector<int>::iterator it;
	std::vector<int>::iterator aux;
	int shortest_span;
	int aux_span;

	if (_nums.size() < 2)
		throw std::logic_error("There are not enough numbers in Span");
	
	tmp = _nums;
	std::sort(tmp.begin(), tmp.end());
	
	it = tmp.begin();
	aux = it + 1;
	shortest_span = *aux - *it;
	
	++aux;
	++it;
	while(aux != tmp.end())
	{
		aux_span = *aux - *it;
		if (aux_span < shortest_span)
			shortest_span = aux_span;
		++it;
		++aux;
	}
	return (shortest_span);
}

int Span::longestSpan()
{
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	int longest_span;

	if (_nums.size() < 2)
		throw std::logic_error("There are not enough numbers in Span");	
	min = std::min_element(_nums.begin(), _nums.end());
	max = std::max_element(_nums.begin(), _nums.end());
	longest_span = *max - *min;
	return(longest_span);
}

void Span::printSpan()
{
	for(std::vector<int>::iterator it = _nums.begin(); it != _nums.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
