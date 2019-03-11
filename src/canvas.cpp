#include "canvas.h"

Canvas::Canvas (unsigned int m_width, unsigned int m_heigth)
{
	this->m_width = m_width;
	this->m_heigth = m_heigth;
	
	// create a default background color
	this->m_bkg_color = Color::WHITE;
	this->image = new color_t[ this->get_size_canvas() ]; 
	this->clear();
}

Canvas::Canvas (unsigned int m_width, unsigned int m_heigth, const Color & m_bkg_color)
{
	this->m_width = m_width;
	this->m_heigth = m_heigth;
	this->m_bkg_color = m_bkg_color;
	this->image = new color_t[ this->get_size_canvas() ]; 
	this->clear();
}

Canvas::~Canvas ()
{
	delete image;
}

Canvas& Canvas::operator= (const Canvas & rhs)
{
	this->m_width = rhs.m_width;
	this->m_heigth = rhs.m_heigth;
	this->m_bkg_color = rhs.m_bkg_color;
	return *this;
}

void Canvas::clear ()
{
	unsigned int size = this->get_size_canvas();
	color_t * colors = m_bkg_color.get_color_value();

	for (unsigned int i=0; i < size; i+=VALUES_PER_PIXEL)
	{
		for (int j=0; j < VALUES_PER_PIXEL; j++)
			this->image[i+j] = colors[j];
	}
}

/**
 * Main functions
 */

#include<iostream>
void Canvas::add_new_shape (Shape *shape)
{ this->shapes.push_back(shape); }

void Canvas::draw () 	
{
	std::vector<POINT> temp;

	for (unsigned int i=0; i < this->shapes.size(); i++)
	{
		shapes[i]->draw();
		std::cout << shapes[i]->to_string();
		temp = shapes[i]->get_pixels();
		for (unsigned int j=0; j < temp.size(); j++)
			this->color_pixel(temp[j], shapes[i]->get_color());
		if (shapes[i]->is_floodfill())
			this->floodfill(shapes[i]->get_pfloodfill(), this->m_bkg_color, shapes[i]->get_fill());
	}

	this->antialising();
}

void Canvas::color_pixel (POINT x, Color *color)
{ this->color_pixel(x.x, x.y, color); }

void Canvas::color_pixel (int x_axis, int y_axis, Color *color)
{
	int init_pixel = this->get_position_pixel(x_axis, y_axis);

	// Get a pixel color
	color_t * color_index = color->get_color_value();

	for (int i=0; i < VALUES_PER_PIXEL; i++)
		this->image[init_pixel+i] = color_index[i];

}

int Canvas::get_position_pixel(int x_axis, int y_axis)
{
	if ( (unsigned int) x_axis > this->m_width || 
		 (unsigned int) y_axis > this->m_heigth ||
		 (unsigned int) x_axis < 1 ||
		 (unsigned int) y_axis < 1)
		return 0;

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

	return init_pixel;
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

void Canvas::set_color_bkg (const Color & color_bkg)
{ 
	this->m_bkg_color = color_bkg; 
	this->clear();
}

void Canvas::set_shapes (std::vector<Shape*> shapes)
{ this->shapes = shapes; }

void Canvas::antialising ()
{
	int sfilter = 3;
	int somar=0, somag=0, somab=0;
	int p_init = 0;
	int gaussian[sfilter][sfilter] = {{1,2,1},
									  {2,4,2},
									  {1,2,1}};
	
	for (unsigned int i =1; i < m_width; i++) 	{
		for (unsigned int j=1; j< m_heigth; j++) {
			
			// convolution
			for (int k=0; k < sfilter; k++) {
				for (int l=0; l < sfilter; l++) {
					p_init = this->get_position_pixel(i+k, j+k);

					somar += this->image[p_init]*gaussian[k][l];
					somag += this->image[p_init+1]*gaussian[k][l];
					somab += this->image[p_init+2]*gaussian[k][l]; 
				}
			}

			// apply result
			p_init = this->get_position_pixel(i+1,j+1);
			this->image[p_init] = somar/16;
			this->image[p_init+1] = somag/16;
			this->image[p_init+2] = somab/16;

			somar = 0;
			somag = 0;
			somab = 0;
		}
	}
}

void Canvas::floodfill (POINT init, Color & old, Color & fill)
{
	if (old == fill) return;
	if (init.x < 0 || init.x >= (int)m_width ) return;
	if (init.y < 0 || init.y >= (int)m_heigth) return;

	int pos = this->get_position_pixel(init.x, init.y);
	Color cpixel = Color(image[pos], image[pos+1], image[pos+2]);
	if ((cpixel == old) and !(cpixel == fill)){
		this->color_pixel(init, &fill);
		this->floodfill(POINT{init.x+1, init.y}, old, fill);
		this->floodfill(POINT{init.x, init.y+1}, old, fill);
		this->floodfill(POINT{init.x-1, init.y}, old, fill);
		this->floodfill(POINT{init.x, init.y-1}, old, fill);
	}
}