#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "color.h"
#include "point.h"

class Object {

private:

	Color *color; 

	Color *color_fill;

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      color       The color border 
	 * @param      color_fill  The color fill
	 */
	Object ( Color *color, Color *color_fill);

	/**
	 * @brief      Destroys the object.
	 */
	~Object ();

	/**
	 * @brief      draw a object in a canvas
	 */
	void draw ();

	/**
	 * Getters and Setters
	 */

	Color* get_color ();

	void set_color (Color *color);

	Color* get_color_fill ();

	void set_color_fill (Color *color_fill);

};

#endif