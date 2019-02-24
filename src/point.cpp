#include "point.h"

Point::Point (int x_axis, int y_axis)
{
	this->x_axis = x_axis;
	this->y_axis = y_axis;
}

Point::~Point(){}

int Point::get_x_axis ()
{ return this->x_axis; }

void Point::set_x_axis (int x)
{ this->x_axis = x; }

int Point::get_y_axis ()
{ return this->y_axis; }

void Point::set_y_axis (int y)
{ this->y_axis = y; }
