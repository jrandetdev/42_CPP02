#include "Fixed.hpp"
#include <iostream>

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
