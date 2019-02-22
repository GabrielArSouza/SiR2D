#include "canvas.h"

Canvas::Canvas (unsigned int m_width, unsigned int m_heigth)
{
	this->m_width = m_width;
	this->m_heigth = m_heigth;
	
	// create a default background color
	Color bkg_color = Color(255, 
							255,
							255);

	this->m_bkg_color = &bkg_color;
	this->image = new color_t[ this->get_size_canvas() ]; 
	this->clear();
}

Canvas::Canvas (unsigned int m_width, unsigned int m_heigth, Color * m_bkg_color)
{
	this->m_width = m_width;
	this->m_heigth = m_heigth;
	this->m_bkg_color = m_bkg_color;
	this->image = new color_t[ m_width*m_heigth ]; 
	this->clear();
}

Canvas::~Canvas ()
{
	delete image;
}

void Canvas::clear ()
{
	unsigned int size = this->get_size_canvas();
	color_t * colors = this->m_bkg_color->get_color_value();

	for (unsigned int i=0; i < size; i+=VALUES_PER_PIXEL)
	{
		for (int j=0; j < VALUES_PER_PIXEL; j++)
			this->image[i+j] = colors[j];
	}
}

color_t * Canvas::get_image ()
{ return this->image; }

unsigned int Canvas::get_width ()
{ return this->m_width; }

unsigned int Canvas::get_heigth ()
{ return this->m_heigth; }

unsigned int Canvas::get_size_canvas ()
{ return this->m_width * this->m_heigth * VALUES_PER_PIXEL; }