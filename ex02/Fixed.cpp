#include "Fixed.hpp"

// ==================== CONSTRUCTORS & DESTRUCTOR ====================

//useful for intialisation
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

Fixed::Fixed(const int value)
{
	this->raw_value = (value << this->fractional_bits);
}

Fixed::Fixed(const float value)
{
	// Round to preserve precision when converting to int
	this->raw_value = round(value * (1 << this->fractional_bits)); 
}

// ==================== ASSIGNMENT OPERATOR ====================

//returns a reference, so return the dereference of this->
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_value = other.raw_value;
	return (*this);
}

// ==================== CONVERSION FUNCTIONS ====================

int Fixed::toInt(void) const
{
	return (this->raw_value >> this->fractional_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->raw_value / (1 << this->fractional_bits));
}

// ==================== ARITHMETIC OPERATORS ====================

/**
 * Addition: (5 × 256) + (3 × 256) = 256 × (5 + 3) = 256 × 8
 * Result is scaled once (correct fixed-point format)
 */
Fixed Fixed::operator+(const Fixed& other)
{
	Fixed result;
	result.raw_value = this->raw_value + other.raw_value;
	return (result);
}
Fixed Fixed::operator-(const Fixed& other)
{
	Fixed result;
	result.raw_value = this->raw_value - other.raw_value;
	return (result);
}

/**
 * Multiplication: (5 × 256) × (3 × 256) = 256^2 × 15
 * Result is scaled twice, so divide by 256 to correct result :)
 * 
 * Else it would be multiplied by 256^2
 */
Fixed Fixed::operator*(const Fixed& other)
{
	Fixed result;
	result.raw_value = (this->raw_value * other.raw_value) >> this->fractional_bits;
	return (result);
}


/**
 * Division: Multiply numerator by 256 before dividing to:
 * 1. Maintain fixed-point scale in result
 * 2. Preserve precision (avoid integer truncation)
 */
Fixed Fixed::operator/(const Fixed& other)
{
	Fixed result;
	result.raw_value = (this->raw_value << this->fractional_bits) / other.raw_value;
	return (result);
}

// ================ COMPARISON OPERATORS =================

//refelction: when I send an operation if (x > y), it returns a boolean, true false.
// so the operator overload need the boolean return type.

bool Fixed::operator<(const Fixed& other)
{
	return (this->raw_value < other.raw_value);
}

bool Fixed::operator>(const Fixed&other)
{
	return (this->raw_value > other.raw_value);
}

bool Fixed::operator<=(const Fixed& other)
{
	return (this->raw_value <= other.raw_value);
}

bool Fixed::operator>=(const Fixed& other)
{
	return !(this->raw_value >= other.raw_value);
}

bool Fixed::operator==(const Fixed& other)
{
	return (this->raw_value == other.raw_value);
}

bool Fixed::operator!=(const Fixed& other)
{
	return (this->raw_value != other.raw_value);
}

// ================= INCREMENT/DECREMENT ==================

/**
 * 3 * 256 = 768
 * 4 * 256 = 1024
 * 1024 - 768 = 256
 * 
 */
//pre increment 
Fixed& Fixed::operator++()
{
	//this->fractional bits is 8, so you get 256 by doing 1 << 8 :)
	this->raw_value += (1 << this->fractional_bits);	//actual increment 
	return (*this);										// return new value by reference
}

// Post increment 
//int is not used, its just so the compiler knows that theyare not the same
//it is purely to distringuish them
Fixed Fixed::operator++(int)
{
	Fixed old_value;
	old_value = (*this);	//copy old value
	operator++();			//prefix incrmeent
	return (old_value);		//return old value
}

//pre decrement
Fixed& Fixed::operator--()
{
	this->raw_value -= (1 << this->fractional_bits);
	return (*this);
}

//postfix decrement
Fixed Fixed::operator--(int)
{
	Fixed old_value;
	old_value = *this;
	operator--();
	return (old_value);
}

// ==================== I/O OPERATORS ====================

// overload the outputstream (ostream) :)
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

// ==================== GETTERS & SETTERS ====================

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (raw_value);
}

void Fixed::setRawBits(int const raw)
{
	this->raw_value = raw;
}
