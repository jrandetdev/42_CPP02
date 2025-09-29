#include "Fixed.hpp"
#include <iostream>


/*
*	Integers can be manipulated very easily by the computer. Floating points
*	not so much. To counter this difficulty, we use fixed point
*	like decimals, 53 and 53.0 is the same representation, its just that it was multiplied
*	by 10^0. 
*	
*	in bina
*/
/**
 * Binary vs decimal representation:
 * just like 53 and 53.0 have the same value as to say (just shifted by 10^0)
 * the same goes with binary when we shift. The binary representation of 
 * 53 110101(2) is the same as 26.5 : 11010.1(2): in 53 there is no 
 * binary point, but in 26.5 there is a binary point just shifted once.
 * Shifting an integer to the right by 1 bit position is the same as 
 * dividing the number by 2. shifting left is the same as multiplying.
 * (multiplying by 2 is the equivalent of multiplying by 10 in a decimnal system)
 * 
 * 
 * 
 * To represent real numbers on computers, we can use the fixed point
 * representation. fixed<w,b> where w is the width of the numnber rep. and 
 * binary point the number of fractional bits. 
 * fixed<8,3> : 00010110 (8 bits, but the 3 right most are fractional)
 * this means it reads as 00010.110 (2) so 2.75. If I treat it as an int 
 * with no decimal point, it reads as 22 but the binary raw value is the same :)
 * 
 * 
 * So in the end, the fixed point representation (raw values in an int)
 * are used for calculations, and then when we want to print it, 
 * then we convert the raw value to an int or a float for 
 * our human brain.
 */
int main()
{
	//test A
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed const c(Fixed(5.05f) / Fixed( 2 ));

		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	return 0;
}
