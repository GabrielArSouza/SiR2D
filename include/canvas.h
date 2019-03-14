#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <iostream>
#include <vector>

#include "color.h"
#include "common.h"
#include "shape.h"
#include "polyline.h"

typedef struct Edge {

    int yMin;
	int yMax;
	int xMin;

	int x_remains;
	int m;
	int m_denominator;
	int m_remains;

} Edge;

class Canvas {

private:
	
	unsigned int m_width;
	unsigned int m_heigth;
	Color m_bkg_color;
	color_t * image;
	std::vector<Shape*> shapes;

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  m_width   The width
	 * @param[in]  m_heigth  The heigth
	 */
	Canvas (unsigned int m_width = 800, unsigned int m_heigth = 600);

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  m_width      The m width
	 * @param[in]  m_heigth     The m heigth
	 * @param      m_bkg_color  The m bkg color
	 */
	Canvas (unsigned int m_width, unsigned int m_heigth, const Color & m_bkg_color);

	/**
	 * @brief      Destroys the object.
	 */
	~Canvas ();

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      clone  The clone
	 */
	Canvas (Canvas && clone);

	Canvas& operator= (const Canvas & rhs);

	/**
	 * @brief      clear the Canvas
	 */
	void clear ();

	/**
	 * @brief draw all shapes of canvas
	 */
	void draw ();

	/**
	 * @brief add a new shape in vector of shapes
	 * 
	 * @param shape the new shape
	 */
	void add_new_shape (Shape *shape);

	/**
	 * @brief      add a color in a pixel
	 *
	 * @param[in]  x_axis  The x axis of a pixel
	 * @param[in]  y_axis  The y axis of a pixel
	 * @param      color   The pixel color 
	 */
	void color_pixel (int x_axis, int y_axis, Color *color);

	void color_pixel (POINT x, Color * color);

	/**
	 * @brief      Gets the image.
	 *
	 * @return     The image.
	 */
	color_t * get_image ();

	/**
	 * @brief      Gets the width.
	 *
	 * @return     The width.
	 */
	unsigned int get_width ();

	/**
	 * @brief      Gets the heigth.
	 *
	 * @return     The heigth.
	 */
	unsigned int get_heigth ();

	/**
	 * @brief      Gets the size canvas.
	 *
	 * @return     The size canvas.
	 */
	unsigned int get_size_canvas ();

	void set_color_bkg (const Color & color_bkg);
	void set_shapes (std::vector<Shape*> shapes);
	void antialising ();
	int get_position_pixel(int x, int y);

	void floodfill (POINT init, Color & old, Color & fill);
};

#endif