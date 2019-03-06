#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "color.h"
#include "common.h"

#include <vector>
#include <string>

class Shape {

protected:

	Color color;
	std::vector<POINT> pixels;

public:

	Shape (const Color &color);

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

	Color * get_color ();
	void set_color (const Color &color);

	std::vector<POINT> get_pixels ();

	virtual std::string to_string();
};

#endif