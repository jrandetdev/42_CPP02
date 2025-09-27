#include "Fixed.hpp"

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

Fixed& Fixed::operator=(const Fixed& other) //returns a reference, a bit like the dereferenced pointed value
{
	std::cout << "Copy assignment operator called" << std::endl;
	raw_value = other.getRawBits();
	return (*this); // I want to return the actual variable referenced, not the address 
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
