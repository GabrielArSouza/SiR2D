#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <iostream>
#include "color.h"
#include "common.h"

class Canvas {

private:
	
	unsigned int m_width;
	
	unsigned int m_heigth;

	Color * m_bkg_color;

	color_t * image;

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
	Canvas (unsigned int m_width, unsigned int m_heigth, Color * m_bkg_color);

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
	 * @brief      clear the Canvas
	 */
	void clear ();

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

};

#endif