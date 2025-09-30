#include "Fixed.hpp"

// ==================== CONSTRUCTORS & DESTRUCTOR ====================

Fixed::Fixed() : raw_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : raw_value(other.raw_value)
{
	std::cout << "Copy constructor called" << std::endl;
}

/**
 * INT TO FIXED: shift left by 8 (multiplication)
 */
Fixed::Fixed(const int value)
{
	this->raw_value = (value << this->fractional_bits);
}

/**
 * for float to fixed, 
 */
Fixed::Fixed(const float value)
{
	// Round to preserve precision when converting to int
	this->raw_value = round(value * (1 << this->fractional_bits)); //round is used to keep the precision which is lost when putting it in an int
}

// ==================== ASSIGNMENT OPERATOR ====================

Fixed& Fixed::operator=(const Fixed& other) //returns a reference, a bit like the dereferenced pointed value
{
	std::cout << "Copy assignment operator called" << std::endl;
	raw_value = other.getRawBits();
	return (*this); // I want to return the actual variable referenced, not the address 
}

// ==================== CONVERSION FUNCTIONS ====================

/**
 * I shift the binary point back to 0. In this whole exercise, 
 * I just keep shifting just by 8 bits (as of this exercise).
 * 
 * FIXED TO INT (do the opposite of the int to fixed): shift right by 8
 * (division)
 */
int		Fixed::toInt(void) const
{
	return (this->raw_value >> this->fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return (((float)this->raw_value / (1 << this->fractional_bits)));
}

// ==================== I/O OPERATORS ====================

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
;
	os << obj.toFloat(); //pushing something in a stream 
	return (os);
}

// ==================== GETTERS & SETTERS ====================

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (raw_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw_value = raw;
}
