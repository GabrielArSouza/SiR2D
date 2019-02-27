#include "circle.h"

/**
 * Constructors
 */

Circle::Circle(POINT center, int radius) : Shape(BLACK, WHITE)
{ 
    this->center = center;
    this->radius = radius;
}

Circle::Circle(POINT center, int radius, Color color) : Shape(&color, &color)
{ 
    this->center = center;
    this->radius = radius;
}


Circle::Circle(POINT center,int radius, Color color, 
               Color fill_color) : Shape (&color, &fill_color)
{ 
    this->center = center;
    this->radius = radius;
}


Circle::Circle(POINT center,int radius, 
               Color *color, Color *fill_color) : Shape (color, fill_color)
{ 
    this->center = center;
    this->radius = radius;
}


Circle::~Circle(){}

/**
 * Principal methods
 */
#include <iostream>

void Circle::plot_octante_circle (POINT p)
{ 
    this->pixels.push_back(POINT {center.x + p.x, center.y + p.y});
    this->pixels.push_back(POINT {center.x + p.x, center.y - p.y});
    this->pixels.push_back(POINT {center.x - p.x, center.y + p.y});
    this->pixels.push_back(POINT {center.x - p.x, center.y - p.y});
    this->pixels.push_back(POINT {center.x + p.y, center.y + p.x});
    this->pixels.push_back(POINT {center.x - p.y, center.y + p.x});
    this->pixels.push_back(POINT {center.x + p.y, center.y - p.x});
    this->pixels.push_back(POINT {center.x - p.y, center.y - p.x});
}
void Circle::draw()
{
    int x = 0;
    int y = this->radius;
    int d = 1 - radius;

    this->plot_octante_circle(POINT{x,y});
    while (y>x)
    {
        if (d < 0)
            d = d + 2*x + 3;
        else{
            d = d + 2*(x-y)+5;
            y--;
        } 
        x++;
        plot_octante_circle(POINT{x,y});
    }
}

/**
 * Getters and Setters 
 */

int Circle::get_radius ()
{ return this->radius; }

void Circle::set_radius (int radius)
{ this->radius = radius; }