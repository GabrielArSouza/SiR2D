#ifndef _CANVAS_H_
#define _CANVAS_H_

#include "color.h"

typedef unsigned int size_t;

class Canvas {

private:
	
	size_t m_width;
	
	size_t m_heigth;

	Color m_bkg_color;

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  m_width   The width
	 * @param[in]  m_heigth  The heigth
	 */
	Canvas (size_t m_width = 800, size_t m_heigth = 600);

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

	

};

#endif