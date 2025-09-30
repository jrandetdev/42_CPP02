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
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	return 0;
}
