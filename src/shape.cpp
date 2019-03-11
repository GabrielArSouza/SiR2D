#include "shape.h"

Shape::Shape (const Color &color, bool floodfill, bool polygon)
{ 
    this->color = color;
    this->floodfill = floodfill;
    this->polygon = polygon;
}

Shape::~Shape (){}

void Shape::draw(){}

Color * Shape::get_color ()
{ return &color; }

void Shape::set_color (const Color &color)
{ this->color = color; }

std::vector<POINT> Shape::get_pixels ()
{ return this->pixels;}

std::string Shape::to_string(){return "I'm a shape\n";}

Color& Shape::get_fill()
{ return this->color; }

void Shape::set_floodfill(bool value)
{ this->floodfill = value;}

bool Shape::is_floodfill()
{ return this->floodfill; }

bool Shape::is_polygon()
{ return polygon; }

std::vector<POINT> Shape::get_pfloodfill()
{  
    std::vector<POINT> p = {POINT{0,0}};
    return p;
}

// void set_pfloodfill(POINT p)
// {}