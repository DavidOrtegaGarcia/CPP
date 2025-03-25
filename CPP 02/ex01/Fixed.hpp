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

		Fixed &operator = (const Fixed &other);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif

