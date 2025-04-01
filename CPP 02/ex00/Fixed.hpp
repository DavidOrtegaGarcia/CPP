#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _raw;
		static const int _fractionalbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		Fixed &operator = (const Fixed &other);
};

#endif

