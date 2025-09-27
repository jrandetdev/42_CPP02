#include "Fixed.hpp"
#include <iostream>


/*
*	Integers can be manipulated very easily by the computer. Floating points
*	not so much. To counter this difficulty, we use fixed point
*/
int main()
{
	//test A
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	//test B 
	// {
	// 	Fixed a;
 
	// 	a.setRawBits(5);
	// 	std::cout << "shifted once (binary shift)" << std::endl;
	// 	std::cout << "same as 5 x 256 so 1280." << std::endl;
	// 	std::cout << a.getRawBits() << std::endl;

	// }
	return 0;
}
