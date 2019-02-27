#include "canvas.h"

Canvas::Canvas (unsigned int m_width, unsigned int m_heigth)
{
	this->m_width = m_width;
	this->m_heigth = m_heigth;
	
	// create a default background color
	Color bkg_color = WHITE;

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

/**
 * Main functions
 */

void Canvas::add_new_shape (Shape *shape)
{ 	this->shapes.push_back(shape);}

void Canvas::draw () 	
{
	std::vector<POINT> temp;

	for (unsigned int i=0; i < this->shapes.size(); i++)
	{
		shapes[i]->draw();
		temp = shapes[i]->get_pixels();
		for (unsigned int j=0; j < temp.size(); j++)
			this->color_pixel(temp[j], shapes[i]->get_color());
	}
}

void Canvas::color_pixel (POINT x, Color *color)
{ this->color_pixel(x.x, x.y, color); }

void Canvas::color_pixel (int x_axis, int y_axis, Color *color)
{
	/**
	 * A imagem está armazena sequenciamente em um grande array
	 * de unsigned char. A ordem de inserção no array é linha por 
	 * linha. Cada pixel possui uma quantidade de valores definida
	 * na constante VALUES_PER_PIXEL. A expressão abaixo define a
	 * quantidade de caracteres necessários para representar uma 
	 * linha da imagem.
	 */
	int line_size = this->m_width * VALUES_PER_PIXEL;


	/**
	 * Com o valor do eixo x do pixel podemos encontrar a possição
	 * do array em que a linha onde o pixel se encontra começa. Como
	 * a representação do array começa em 0 é necessário diminuir 1
	 * do valor de x_axis recebido. A expressão abaixo encontra o 
	 * início da linha onde o pixel está.
	 */
	int init_line_of_pixel = (x_axis - 1) * line_size;


	/**
	 * Seguindo a lógica para encontrar o início da linha, agora 
	 * é necessário encontrar a posição onde começa o pixel. A 
	 * expressão abaixo realiza este cálculo.
	 */
	int init_pixel = init_line_of_pixel + (y_axis-1) * VALUES_PER_PIXEL ;

	// Get a pixel color
	color_t * color_index = color->get_color_value();

	for (int i=0; i < VALUES_PER_PIXEL; i++)
		this->image[init_pixel+i] = color_index[i];

}

/**
 * Getters and Setters 
 */

color_t * Canvas::get_image ()
{ return this->image; }

unsigned int Canvas::get_width ()
{ return this->m_width; }

unsigned int Canvas::get_heigth ()
{ return this->m_heigth; }

unsigned int Canvas::get_size_canvas ()
{ return this->m_width * this->m_heigth * VALUES_PER_PIXEL; }