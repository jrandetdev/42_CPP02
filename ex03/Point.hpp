#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

typedef	struct s_vec
{
	Fixed const x;
	Fixed const y;
}	t_vec;


class Point
{
	private:
		Fixed const x;
		Fixed const y;
		t_vec vec;
	public:
		Point();
		~Point();

		Point(const float param_x, const float param_y);
		//copy constructor for Point
		Point(const Point& other);
		//copy assignment operator
		Point& operator=(const Point& other);
		Fixed& cross_product(Point i, Point j, Point p);
};


#endif