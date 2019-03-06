#include "triangle.h"

// constructors

Triangle::Triangle(POINT p1, POINT p2, POINT p3)
    : Shape (Color::BLACK)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::Triangle(POINT p1, POINT p2, POINT p3, const Color &color) 
    : Shape (color)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}


Triangle::~Triangle(){}

// Principal methods

 void Triangle::draw()
 {
    std::vector<POINT> aux;

    Line l1 = Line (&p1, &p2, color);
    l1.draw();
    aux = l1.get_pixels();
    for(std::vector<POINT>::iterator it = aux.begin(); it != aux.end(); ++it)
        this->pixels.push_back(*it);

    Line l2 = Line (&p1, &p3, color);
    l2.draw();
    aux = l2.get_pixels();
    for(std::vector<POINT>::iterator it = aux.begin(); it != aux.end(); ++it)
        this->pixels.push_back(*it);
   
    Line l3 = Line (&p2, &p3, color);    
    l3.draw();
    aux = l3.get_pixels();
    for(std::vector<POINT>::iterator it = aux.begin(); it != aux.end(); ++it)
        this->pixels.push_back(*it);
    
 }


// Getters and Setters

std::vector<POINT> Triangle::get_points ()
{   std::vector<POINT> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    return points; 
}

void Triangle::set_points (POINT p1, POINT p2, POINT p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

std::string Triangle::to_string()
{  return "I'm a triangle and my color is " + color.to_string() + "\n"; }