#include "line.h"

Line::Line (POINT *p1, POINT *p2, 
            Color *color, Color *color_fill) : Shape(color, color_fill)
{
	try {
        if (p1->x > p2->x) {
            throw 1;
        } else {            
			this->p1 = p1;
			this->p2 = p2;
        }
    } catch(int erro) {
        if (erro == 1) {
            std::cout << "Invalid Line declaration..." << std::endl;
        }
    }
}

Line::~Line (){}

/**
 * Principal methods
 */

std::vector<POINT> Line::draw ()
{
    std::cout << "chamou";
    std::vector<POINT> pixels;
    int xa, xb, ya, yb;

	xa = this->p1->x;
	xb = this->p2->x;

	ya = this->p1->y;
	yb = this->p2->y;

	int delta_x = xb - xa;
	int delta_y = yb - ya;

	int pk = 2 * delta_y - delta_x;
	
	pixels.push_back(POINT {xa, ya});

	for ((xa+1); xa <= xb; xa++ )
	{
		if (pk < 0) 
			pk = pk + 2 * delta_y;
		else 
		{
			ya = ya+1;
			pk = pk + 2* delta_y - 2*delta_x;
		}
		std::cout << "print a pixel (" << xa << "," << ya << ")\n";
		pixels.push_back(POINT {xa, ya});
	}

    return pixels;
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