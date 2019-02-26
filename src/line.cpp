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

POINT* Line::get_p1 ()
{ return this->p1; }

void Line::set_p1 (POINT *p1)
{ this->p1 = p1; }

POINT* Line::get_p2 ()
{ return this->p2; }

void Line::set_p2 (POINT *p2)
{ this->p2 = p2; }