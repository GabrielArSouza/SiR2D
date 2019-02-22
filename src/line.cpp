#include "line.h"

Line::Line (Point *p1, Point *p2, Color *color, Color *color_fill) : Object(color, color_fill)
{
	this->p1 = p1;
	this->p2 = p2;
}

Point* Line::get_p1 ()
{ return this->p1; }

void Line::set_p1 (Point *p1)
{ this->p1 = p1; }

Point* Line::get_p2 ()
{ return this->p2; }

void Line::set_p2 (Point *p2)
{ this->p2 = p2; }