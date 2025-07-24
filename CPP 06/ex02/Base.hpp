#pragma once 

#include <iostream>

class Base
{
	public :
		virtual ~Base(){}; // If the function is not asbtract (=0) we must implement the virtual function ({})
};

class A : public Base {};
class B : public Base {};
class C : public Base {};