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
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

		Fixed(const Fixed& other); // this is a cpopy constructor
		
		//copy assignment operator
		Fixed&	operator=(const Fixed& other);

		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);

		bool Fixed::operator<(const Fixed& other);
		bool Fixed::operator>(const Fixed&other);
		bool Fixed::operator<=(const Fixed& other);
		bool Fixed::operator>=(const Fixed& other);
		bool Fixed::operator==(const Fixed& other);
		bool Fixed::operator!=(const Fixed& other);

		Fixed& operator++();
		Fixed Fixed::operator++(int);
		Fixed& Fixed::operator--();
		Fixed Fixed::operator--(int);
		
		int		toInt(void) const;
		float	toFloat(void) const;

		int		getRawBits(void) const; // returns the raw value of the fixed point numnber
		void	setRawBits(int const raw); //sets the raw value of the fixed point number
	};

	std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif



