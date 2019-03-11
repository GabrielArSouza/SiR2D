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
	
	bool floodfill;
	bool polygon;

public:

	Shape (const Color &color, bool floodfill = false, bool polygon = false);

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
	virtual Color& get_fill();
	virtual std::vector<POINT> get_pfloodfill();
    // virtual void set_pfloodfill(POINT p);

	bool is_floodfill();
    void set_floodfill(bool value);

	bool is_polygon();
};

#endif