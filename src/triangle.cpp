#include "triangle.h"

// constructors

Triangle::Triangle(POINT p1, POINT p2, POINT p3)
    : Shape (BLACK, BLACK)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::Triangle(POINT p1, POINT p2, POINT p3, 
    Color color) : Shape (&color, &color)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}


Triangle::Triangle(POINT p1, POINT p2, POINT p3, 
    Color color, Color fill_color) : Shape(&color, &fill_color)
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

    Line l1 = Line (&p1, &p2, color, color_fill);
    l1.draw();
    aux = l1.get_pixels();
    for(std::vector<POINT>::iterator it = aux.begin(); it != aux.end(); ++it)
        this->pixels.push_back(*it);

    Line l2 = Line (&p1, &p3, color, color_fill);
    l2.draw();
    aux = l2.get_pixels();
    for(std::vector<POINT>::iterator it = aux.begin(); it != aux.end(); ++it)
        this->pixels.push_back(*it);
   
    Line l3 = Line (&p2, &p3, color, color_fill);    
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
