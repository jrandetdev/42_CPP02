#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
	private:
		Fixed const x;
		Fixed const y;
		//copy assignment operator
		Point& operator=(const Point& other);
	public:
		Point();
		~Point();

		Point(const float param_x, const float param_y);
		//copy constructor for Point
		Point(const Point& other);
		// Fixed	getTriangleArea(const Point a, const Point b, const Point c);
		static Fixed triangle_area(const Point& p1, const Point& p2, const Point& p3);
		static bool	is_on_line(const Point& a, const Point& b, const Point& c, const Point& point);
		static Fixed cross_product_sign(const Point& p1, const Point& p2, const Point& p3);
};


#endif
