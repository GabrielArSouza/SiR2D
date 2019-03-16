#ifndef _LINE_H_
#define _LINE_H_

#include "shape.h"
#include "common.h"

#include <iostream>
#include <stdlib.h> 

/**
 * @brief A class for Line, extends Shape
 * 
 */
class Line : public Shape {

private:

	POINT p1; //<! point 1
	POINT p2; //<! point 2

	/**
	 * @brief plot line low
	 * 
	 * @param x0 the x axis point 1
	 * @param y0 the y axis point 1
	 * @param x1 the x axis point 2
	 * @param y1 the y axis point 2
	 */
	void plot_line_low  (int x0, int y0, int x1, int y1);
	
	/**
	 * @brief ploat line heigh
	 * 
	 * @param x0  the x axis point 1
	 * @param y0  the y axis point 1
	 * @param x1  the x axis point 2
	 * @param y1  the x axis point 2
	 */
	void plot_line_high (int x0, int y0, int x1, int y1);

public:

	/**
	 * @brief Construct a new Line object
	 * 
	 * @param p1 The first point
	 * @param p2 The second point
	 */
	Line (POINT p1, POINT p2);

	/**
	 * @brief Construct a new Line object
	 * 
	 * @param p1 The first point
	 * @param p2 The second point
	 * @param color line's color
	 */
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

	/**
	 * @brief Get the p1 object
	 * 
	 * @return POINT a pointq
	 */
	POINT get_p1 ();

	/**
	 * @brief Set the p1 object
	 * 
	 * @param p1 point 1
	 */
	void set_p1 (POINT p1);

	/**
	 * @brief Get the p2 object
	 * 
	 * @return POINT point 2
	 */
	POINT get_p2 ();

	/**
	 * @brief Set the p2 object
	 * 
	 * @param p2 point 2
	 */
	void set_p2 (POINT p2);

	/**
	 * @brief description of class
	 * 
	 * @return std::string the descriptions string
	 */
	std::string to_string();

};

#endif