#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>
#include <string>
//all const member members must be initialised at the time of creation

class Fixed
{
	private:
		int					raw_value;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other); // this is a cpopy constructor
		Fixed& operator=(const Fixed& other); // this is a copy assignment operator
		~Fixed();
		int		getRawBits(void) const; // returns the raw value of the fixed point numnber
		void	setRawBits(int const raw); //sets the raw value of the fixed point number
	};

#endif



