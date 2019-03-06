#include "color.h"

Color::Color( color_t r , color_t g , color_t b )
{
	this->channels[0] = r;
	this->channels[1] = g;
	this->channels[2] = b;
}

Color::Color (const Color &clone)
{
	this->channels[0] = clone.channels[0];
	this->channels[1] = clone.channels[1];
	this->channels[2] = clone.channels[2];
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

std::string Color::to_string()
{
	return "rgb(" + std::to_string(channels[0]) + "," + std::to_string(channels[1])
			 + "," + std::to_string(channels[2]) + ")";
}

const Color Color::RED(255,0,0);
const Color Color::GREEN(0, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::BLACK(0,0,0);
const Color Color::WHITE(255,255,255);
const Color Color::YELLOW(255,255,0);
const Color Color::PINK(250, 91, 138);
const Color Color::ORANGE(254, 123, 33);
const Color Color::BOLDGREEN(34, 90, 14);
const Color Color::SKYBLUE(141, 207, 251);
