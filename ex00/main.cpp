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
		Fixed b( a );
		Fixed c;

		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	//test B 
	{
		Fixed a;
 
		a.setRawBits(5);
		std::cout << "shifted once (binary shift)" << std::endl;
		std::cout << "same as 5 x 256 so 1280." << std::endl;
		std::cout << a.getRawBits() << std::endl;

	}
	return 0;
}
