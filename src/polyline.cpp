#include "polyline.h"

Polyline::Polyline( std::vector<Shape*> lines, const Color &color )
    : Shape(color)
{ this->lines = lines; }

Polyline::Polyline( std::vector<POINT> points, const Color &color )
    : Shape(color)
{ 
    POINT aux;
    if ( !points.empty() )
        aux = points[0];

    for (std::vector<POINT>::iterator it = points.begin()+1;
         it != points.end();
         it++)
    {   
        lines.push_back(new Line(aux, *it, color));
        aux = *it;
    }
}

Polyline::~Polyline()
{}

void Polyline::draw()
{
    std::vector<POINT> aux;
    for (unsigned int i=0; i < lines.size(); i++)
    {
        this->lines[i]->draw();
        aux = lines[i]->get_pixels();
        for(std::vector<POINT>::iterator it = aux.begin(); it != aux.end(); ++it)
            this->pixels.push_back(*it);
    }

}

std::string Polyline::to_string()
{  return "I'm a polyline and my color is " + color.to_string() + "\n"; }