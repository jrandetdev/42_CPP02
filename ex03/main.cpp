#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	{
		std::cout << "Point on line, should print outside\n";
		Point a(2, 4);
		Point b(3.38, 7.1);
		Point c(5, 4);
		Point p(3, 4);

		
		if (bsp(a, b, c, p))
			std::cout << "point is inside the triangle" << std::endl;
		else
			std::cout << "point is outside the triangle" << std::endl;
	}
	{
		std::cout << "Point inside, should print inside\n";
		Point a(2, 4);
		Point b(3.38, 7.1);
		Point c(5, 4);
		Point p(3, 5);

		
		if (bsp(a, b, c, p))
			std::cout << "point is inside the triangle" << std::endl;
		else
			std::cout << "point is outside the triangle" << std::endl;
	}
	{
		std::cout << "Point outside, should print outside\n";
		Point a(2, 4);
		Point b(3.38, 7.1);
		Point c(5, 4);
		Point p(4, 2);

		
		if (bsp(a, b, c, p))
			std::cout << "point is inside the triangle" << std::endl;
		else
			std::cout << "point is outside the triangle" << std::endl;
	}
	return (0);
}
