#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int _raw;
		static const int _fbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator = (const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

