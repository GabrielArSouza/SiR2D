#include "object.h"

Object::Object ( Color *color, Color *color_fill)
{
	this->color = color;
	this->color_fill = color_fill;
}

Color Object::get_color ()
{ return this->color; }

void Object::set_color (Color *color)
{ this->color = color; }

Color Object::get_color_fill ()
{ return this->color_fill; }

void set_color_fill (Color *color)
{ this->color_fill = color_fill; }