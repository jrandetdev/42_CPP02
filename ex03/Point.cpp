#include "Point.hpp"

// ====================== CONST / DEST ==========================

Point::Point() : x{}, y{}
{
	std::cout << "Point: Default construtor called." << std::endl;
}

Point::Point(const float param_x, const float param_y) : x(param_x), y(param_y)
{
	return ;
}

Point::~Point()
{
	std::cout << "Point: Default destructor called." << std::endl;
}

// ==================== COPY CONSTRUCTOR ========================

Point::Point(const Point& other) : x(other.x), y(other.y) // these are const 
{
	return;
}

// ==================== ASSIGNMENT OPERATOR ====================

Point& Point::operator=(const Point& other)
{
	return ;
}

