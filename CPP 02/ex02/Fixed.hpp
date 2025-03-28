#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _raw;
		static const int _fractionalbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int raw_int);
		Fixed(const float raw_float);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		static 			Fixed	&min(Fixed &num1, Fixed &num2);
		static  const 	Fixed	&min(const Fixed &num1, const Fixed &num2);
		static 			Fixed	&max(Fixed &num1, Fixed &num2);
		static  const	Fixed	&max(const Fixed &num1, const Fixed &num2);

		Fixed &operator = (const Fixed &other);

		bool operator > (const Fixed &other) const;
		bool operator < (const Fixed &other) const;
		bool operator >= (const Fixed &other) const;
		bool operator <= (const Fixed &other) const;
		bool operator == (const Fixed &other) const;
		bool operator != (const Fixed &other) const;

		Fixed operator + (const Fixed &other);
		Fixed operator - (const Fixed &other);
		Fixed operator * (const Fixed &other);
		Fixed operator / (const Fixed &other);

		Fixed &operator ++(); //Pre increment
		Fixed operator ++(int); //Post increment
		Fixed &operator --();
		Fixed operator --(int);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif

