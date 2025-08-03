#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other)
{
	_result = other._result;
}

RPN::~RPN(){}

RPN &RPN::operator = (const RPN &other)
{
	if(this != &other)
		_result = other._result;
	return(*this);
}

void RPN::makeOperations(char *expression)
{
	if (!checkExpression(expression))
		throw std::logic_error("Invalid expression");
	for(int i = 0; expression[i]; i++)
	{
		if (i % 2 == 0)	
		{
			if (isdigit(expression[i]))
				_result.push(expression[i] - '0');
			else
				doOperation(expression[i], _result);
		}
	}
	std::cout << _result.top() << std::endl;
}


bool checkExpression(char *expression)
{	
	int nums = 0;
	int i = 0;

	for(; expression[i]; i++)
	{
		if(i % 2 == 1 && expression[i] != ' ')
			return (false);
		else if (i % 2 == 0)
		{ 
			if (isdigit(expression[i]))
				nums++;
			else if (isOperator(expression[i]) && nums >= 2)
				nums--;
			else
				return(false);
		}
	}
	if (i == 0 || expression[i - 1] == ' ')
		return(false);
	return(nums == 1);
}

bool isOperator(char c)
{
	char operators[4] = {'+', '-', '/', '*'};
	for(int i = 0; i < 4; i++)
	{
		if (c == operators[i])
			return (true);
	}
	return (false);
}

void doOperation(char oper, std::stack<int> &result)
{
	int num2 = result.top();
	result.pop();
	int num1 = result.top();

	switch(oper)
	{
		case '+':
			result.push(num1 + num2);
			break;
		case '-':
			result.push(num1 - num2);
			break;
		case '/':
			if (num2 == 0)
				throw std::logic_error("Division by 0 is not allowed");
			result.push(num1 / num2);
			break;
		case '*':
			result.push(num1 * num2);
			break;
	}
}
