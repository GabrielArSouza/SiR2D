#include "color.h"

Color::Color( color_t r , color_t g , color_t b )
{
	this->channels[0] = r;
	this->channels[1] = g;
	this->channels[2] = b;
}

Color& Color::operator= (const Color & rhs)
{
	for (int i=0; i < 3; ++i )
		*(channels+i) = *(rhs.channels+i);

	return *this;
}

bool Color::operator== (const Color & rhs)
{
	for (int i=0; i < 3; ++i)
		if (channels[i] != rhs.channels[i])
			return false;
		
	return true;
}

Color::~Color(){}

color_t * Color::get_color_value ()
{ return channels; }
