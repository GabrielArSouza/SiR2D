#include "line.h"

Line::Line (POINT *p1, POINT *p2, 
            Color *color, Color *color_fill) : Shape(color, color_fill)
{
	this->p1 = p1;
	this->p2 = p2;
}

Line::Line (POINT *p1, POINT *p2, 
			Color color) : Shape(&color, &color) 
{
	this->p1 = p1;
	this->p2 = p2;
}

Line::Line (POINT *p1, POINT *p2, 
		Color color, Color color_fill) : Shape(&color, &color_fill)
{
	this->p1 = p1;
	this->p2 = p2;
}


Line::~Line (){}

/**
 * Principal methods
 */

void Line::plot_line_low  (int x0, int y0,
					  	   int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;

	if (dy < 0)
	{ yi = -1; dy = -dy; }

	int pk = 2*dy - dx;
	int y = y0;

	for (int x = x0; x <= x1; x++)
	{
		this->pixels.push_back(POINT {x, y});
		if (pk > 0) {
			y = y + yi;
			pk = pk - 2*dx;
		}	
		pk = pk + 2*dy;
	}
	
}

void Line::plot_line_high (int x0, int y0, 
						   int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;

	if (dx < 0) {
    	xi = -1;
    	dx = -dx;
	}

	int pk = 2*dx - dy;
  	int x = x0;

	for (int y = y0; y < y1; y++)
    {
		this->pixels.push_back(POINT {x, y});
		if (pk > 0){
			x = x + xi;
			pk = pk - 2*dy;
		}
		pk = pk + 2*dx;
	}
  
}

void Line::draw ()
{
    int xa, xb, ya, yb;

	xa = this->p1->x;
	xb = this->p2->x;

	ya = this->p1->y;
	yb = this->p2->y;

	if ( abs(yb - ya) < abs(xb - xa)){
		if (xa > xb)
			this->plot_line_low(xb, yb, xa, ya);
		else 
			this->plot_line_low(xa, ya, xb, yb);
	} else {
		if (ya > yb)
			this->plot_line_high(xb, yb, xa, ya);
		else 
			this->plot_line_high(xa, ya, xb, yb);
	}
}

/**
 * Getters and Setters 
 */

POINT* Line::get_p1 ()
{ return this->p1; }

void Line::set_p1 (POINT *p1)
{ this->p1 = p1; }

POINT* Line::get_p2 ()
{ return this->p2; }

void Line::set_p2 (POINT *p2)
{ this->p2 = p2; }