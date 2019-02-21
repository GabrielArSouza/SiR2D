#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "color.h"

typedef unsigned int size_t;

class Canvas {

private:
	
	size_t m_width;
	
	size_t m_heigth;

	Color m_bkg_color;

};

#endif