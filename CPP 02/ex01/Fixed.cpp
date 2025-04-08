#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed::Fixed(const int raw_int)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = raw_int << _fractionalbits;
};

Fixed::Fixed(const float raw_float)
{
	std::cout << "Float constructor called" << std::endl;
	_raw = roundf(raw_float *(1 << _fractionalbits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Accedemos con -> porque this es un puntero 
// y con . porque other es una referencia
Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_raw = other._raw;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	return (out << fixed.toFloat()); // Pasa el numero en float al stnd output
}