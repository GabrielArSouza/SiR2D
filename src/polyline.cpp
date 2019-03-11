#include "polyline.h"

Polyline::Polyline( std::vector<Shape*> lines,bool is_polygon, 
    bool floodfill , std::vector<POINT> p, const Color &color)
    : Shape(color, floodfill, is_polygon)
{ 
    this->lines = lines; 
    this->p_floodfill = p;
}

Polyline::Polyline( std::vector<POINT> points, bool is_polygon,
     bool floodfill , std::vector<POINT> p,  const Color &color)
    : Shape(color, floodfill, is_polygon)
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

    this->p_floodfill = p;
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

std::vector<POINT> Polyline::get_pfloodfill(){
    return p_floodfill;
}
// void Polyline::set_pfloodfill(POINT p){
//     this->p_floodfill = p;
// }

Color& Polyline::get_fill()
{ return this->fill_color;}

void Polyline::set_fill (const Color & color)
{ this->fill_color = color; }