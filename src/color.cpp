#include "color.h"

Color::Color( color_t r , color_t g , color_t b )
{
	this->channels[0] = r;
	this->channels[1] = g;
	this->channels[2] = b;
}

