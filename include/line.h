#ifndef _LINE_H_
#define _LINE_H_

#include "object.h"
#include <iostream>
class Line : public Object {

private:

	Point *p1;

	Point *p2;

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      p1    The point 1
	 * @param      p2    The point 2
	 */
	Line (Point *p1, Point *p2, Color *color, Color *color_fill);

	/**
	 * @brief      Destroys the object.
	 */
	~Line ();

	/**
	 * Getters and Setters
	 */

	Point* get_p1 ();

	void set_p1 (Point *p1);

	Point* get_p2 ();

	void set_p2 (Point *p2);

};

#endif