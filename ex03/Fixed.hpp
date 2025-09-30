#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>
#include <string>
#include <cmath>
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

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		//the const at the end means you do not modify the object's data
		bool operator<(const Fixed& other) const; // je t garatie que l'instance de ma classe ne serra pas modifie (instance a gauche implicite de l'operateur)
		bool operator>(const Fixed&other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed &x, Fixed& y);
		static const Fixed& min(const Fixed& x, const Fixed& y);
		static Fixed& max(Fixed &x, Fixed &y);
		static const Fixed& max(const Fixed &x, const Fixed& y);

		int		toInt(void) const;
		float	toFloat(void) const;

		int		getRawBits(void) const; // returns the raw value of the fixed point numnber
		void	setRawBits(int const raw); //sets the raw value of the fixed point number
	};

	std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif



