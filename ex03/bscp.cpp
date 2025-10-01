#include "Fixed.hpp"
#include "Point.hpp"


Fixed Point::cross_product_sign(const Point& p1, const Point& p2, const Point& p3)
{
	return ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
}

Fixed Point::triangle_area(const Point& p1, const Point& p2, const Point& p3)
{
	Fixed area = ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y) / 2);
	return (area > 0) ? area : (area*(-1));
}

bool	Point::is_on_line(const Point& a, const Point& b, const Point& c, const Point& point)
{
	if ((triangle_area(a, b , point) + triangle_area(c, b, point)) == triangle_area(a, b, c))
		return (true);
	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1;
	Fixed d2;
	Fixed d3;
	bool has_neg, has_pos;

	if (Point::is_on_line(a, b, c, point))
		return (false);
	d1 = Point::cross_product_sign(point, a, b);
	d2 = Point::cross_product_sign(point, b, c);
	d3 = Point::cross_product_sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	if (has_neg && has_pos)
		return (false);
	return (true);
}
