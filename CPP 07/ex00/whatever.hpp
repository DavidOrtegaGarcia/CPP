#pragma once 

template<typename T>
void  swap(T &var1, T &var2)
{
	T aux;

	aux = var1;
	var1 = var2;
	var2 = aux;
}

template<typename T>
T min(const T &var1, const T &var2)
{
	return((var1 < var2) ? var1 : var2); // = if (var1 < var2) return(var1) else return(var2)
}

template<typename T>
T max(const T &var1, const T &var2)
{
	return((var1 > var2) ? var1 : var2);
}