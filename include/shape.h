#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "color.h"
#include "common.h"

#include <vector>

class Shape {

protected:

	Color *color; 

	Color *color_fill;

	std::vector<POINT> pixels;

public:

	/**
	 * @brief      Constructs the Shape.
	 *
	 * @param      color       The color border 
	 * @param      color_fill  The color fill
	 */
	Shape ( Color *color, Color *color_fill);

	Shape (Color color, Color color_fill);
	/**
	 * @brief      Destroys the Shape.
	 */
	~Shape ();

	/**
	 * @brief      draw a Shape in a canvas
	 */
	virtual void draw ();

	/**
	 * Getters and Setters
	 */

	Color* get_color ();

	void set_color (Color *color);

	Color* get_color_fill ();

	void set_color_fill (Color *color_fill);

	std::vector<POINT> get_pixels ();

};

#endif