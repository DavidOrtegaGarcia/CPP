#pragma once 

#include <iostream>
#include <cctype>
#include <stack>

class RPN
{
	private:
		std::stack<int> _result;
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN &operator = (const RPN &other);

		void makeOperations(char *expression);
};
//Utils
bool checkExpression(char *expression);
bool isOperator(char c);
void doOperation(char oper, std::stack<int> &result);