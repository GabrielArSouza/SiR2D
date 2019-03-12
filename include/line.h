#ifndef _LINE_H_
#define _LINE_H_

#include "shape.h"
#include "common.h"

#include <iostream>
#include <stdlib.h> 

class Line : public Shape {

private:

	POINT p1;
	POINT p2;

	void plot_line_low  (int x0, int y0, int x1, int y1);
	void plot_line_high (int x0, int y0, int x1, int y1);

public:

	Line (POINT p1, POINT p2);

	Line (POINT p1, POINT p2, const Color &color);


	/**
	 * @brief      Destroys the Shape.
	 */
	~Line ();

	/**
	 * @brief draw a line on canvas
	 * 
	 * @param canvas the canvas
	 */
	void draw ();

	/**
	 * Getters and Setters
	 */

	POINT get_p1 ();

	void set_p1 (POINT p1);

	POINT get_p2 ();

	void set_p2 (POINT p2);

	std::string to_string();

};

#endif