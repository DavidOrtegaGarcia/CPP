#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
	private:
		std::vector<int> _nums;
		unsigned int _max_size;
	public:
		Span(unsigned int size);
		Span(const Span &other);
		~Span();
		Span &operator = (const Span &other);

		void addNumber(int num);
		void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);

		int shortestSpan();
		int longestSpan();
		void printSpan();


};