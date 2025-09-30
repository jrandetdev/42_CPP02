#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(4.4, 10.5);
	Point b(1.4, 6.3);
	Point c(7.5, 7.4);
	Point p(4.34, 8.85);

	
	if (bsp(a, b, c, p))
		std::cout << "point is inside the triangle" << std::endl;
	else
		std::cout << "point is outside the triangle" << std::endl;
	return (0);
}
