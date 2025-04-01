#include "Fixed.hpp"

//----CONSTRUCTORS----
Fixed::Fixed() : _raw(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed::Fixed(const int raw_int)
{
	_raw = raw_int << _fractionalbits; // same as raw * (2^fractional_bits)
};

Fixed::Fixed(const float raw_float)
{
	_raw = roundf(raw_float *(1 << _fractionalbits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//----OPERATORS----
//---Comparison operators---
// Accedemos con -> porque this es un puntero y con . porque other es una referencia
Fixed &Fixed::operator = (const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_raw = other.getRawBits();
	return (*this);
}

bool Fixed::operator > (const Fixed &other) const
{
	return(_raw > other.getRawBits());
}

bool  Fixed::operator < (const Fixed &other) const
{
	return(_raw < other.getRawBits());
}

bool  Fixed::operator <= (const Fixed &other) const
{
	return(_raw <= other.getRawBits());
}

bool  Fixed::operator >= (const Fixed &other) const
{
	return(_raw >= other.getRawBits());
}

bool  Fixed::operator == (const Fixed &other) const  
{
	return(_raw == other.getRawBits());
}	

bool  Fixed::operator != (const Fixed &other) const 
{
	return(_raw != other.getRawBits());
}


//---Arithmetic operators---
Fixed Fixed::operator + (const Fixed &other)
{
	Fixed result(this->toFloat() + other.toFloat());
	
	return(result);
}

Fixed Fixed::operator - (const Fixed &other) 
{
	Fixed result(this->toFloat() - other.toFloat());
	
	return(result);
}

Fixed Fixed::operator * (const Fixed &other)
{
	Fixed result(this->toFloat() * other.toFloat());
	
	return(result);
}

Fixed Fixed::operator / (const Fixed &other)
{
	Fixed result(this->toFloat() / other.toFloat());
	
	return(result);
}

//---Increment/Decrement operator

Fixed &Fixed::operator ++() //Pre increment
{
	_raw++;
	return(*this);
}

Fixed Fixed::operator ++(int) //Post increment
{
	Fixed tmp(*this);

	_raw++;
	return(tmp);
}

Fixed &Fixed::operator --()
{
	_raw--;
	return(*this);
}

Fixed Fixed::operator --(int)
{
	Fixed tmp(*this);

	_raw--;
	return(tmp);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	return (out << fixed.toFloat()); // Pasa el numero en float al stnd output
}


//----Functions----
int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return(_raw);
}
void Fixed::setRawBits(int const raw)
{
	_raw = raw;
}

int Fixed::toInt(void) const
{
	return (_raw >> _fractionalbits);
}

float Fixed::toFloat(void) const
{
	return ((float)_raw / (1 << _fractionalbits));
}

Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	return((num1 <= num2) ? num1 : num2);
}

Fixed	const &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	return((num1 <= num2) ? num1 : num2);
}

Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	return((num1 >= num2) ? num1 : num2);
}

Fixed	const &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	return((num1 >= num2) ? num1 : num2);
}
