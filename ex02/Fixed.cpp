#include "Fixed.hpp"

//construvtor

Fixed::Fixed() : raw_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->raw_value = (value << this->fractional_bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	this->raw_value = round(value * (1 << this->fractional_bits)); //round is used to keep the precision which is lost when putting it in an int
}

int		Fixed::toInt(void) const
{
	return (this->raw_value >> this->fractional_bits);
}

float	Fixed::toFloat(void) const
{
	std::cout << "\nto float has been called" << std::endl;
	return (((float)this->raw_value / (1 << this->fractional_bits)));
}

Fixed::Fixed(const Fixed& other) : raw_value(other.raw_value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	Fixed::operator=(const Fixed& other) //returns a reference, a bit like the dereferenced pointed value
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_value = other.raw_value;
	return (*this); // I want to return the actual variable referenced, not the address 
}

Fixed	Fixed::operator+(const Fixed& other)
{
	Fixed	result = (this->raw_value + other.raw_value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other)
{
	Fixed result = (this->raw_value - other.raw_value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed result;
	result.raw_value = (this->raw_value * other.raw_value) / (1 << this->fractional_bits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other)
{
	Fixed result;
	result.raw_value = ((this->raw_value * (1 << this->fractional_bits)) / other.raw_value);
	return (result);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat(); //pushing something in a stream 
	return (os);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (raw_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw_value = raw;
}
