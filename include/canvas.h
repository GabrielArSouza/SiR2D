#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <iostream>
#include <vector>

#include "color.h"
#include "common.h"
#include "shape.h"
#include "polyline.h"
#include "edge.h"

class Canvas {

private:
	
	unsigned int m_width;       //<! width of image
	unsigned int m_heigth;      //<! height of image
	Color m_bkg_color;          //<! canvas background color
	color_t * image;            //<! image representation (a array of unsigned int)
	std::vector<Shape*> shapes; //<! all shapes in canvas

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
	 * @param[in]  m_width      The width
	 * @param[in]  m_heigth     The heigth
	 * @param      m_bkg_color  The background color
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

	/**
	 * @brief the overload of assignment operator
	 *  
	 * @param rhs  the new Canvas
	 * @return Canvas&  A new Canvas equals rhs
	 */
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

	/**
	 * @brief  add a color in a pixel
	 * 
	 * @param x     a point of pixel
	 * @param color the color of pixel
	 */
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

	/**
	 * @brief Set the color bkg object
	 * 
	 * @param color_bkg the background color
	 */
	void set_color_bkg (const Color & color_bkg);
	
	/**
	 * @brief Set the shapes object
	 * 
	 * @param shapes The new vector of shapes
	 */
	void set_shapes (std::vector<Shape*> shapes);
	
	/**
	 * @brief apply antialising algorithm in image
	 * 
	 */
	void antialising ();

	/**
	 * @brief Get the position pixel object
	 * 
	 * @param x the x axis
	 * @param y the y axis
	 * @return int the pixel's position in image array
	 */
	int get_position_pixel(int x, int y);

	/**
	 * @brief  Algorith of filling
	 * 
	 * @param init  The init point
	 * @param old   The old color
	 * @param fill  The new color
	 */
	void floodfill (POINT init, Color & old, Color & fill);

};

#endif