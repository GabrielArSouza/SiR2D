#ifndef _POINT_H_
#define _POINT_H_

class Point {

private:

	int x_axis;
	int y_axis;

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param[in]  x_axis  The x axis
	 * @param[in]  y_axis  The y axis
	 */
	Point (int x_axis, int y_axis);

	/**
	 * @brief      Destroys the object.
	 */
	~Point();

	/**
	 * Getters and Setters
	 */

	int get_x_axis ();

	void set_x_axis (int x);

	int get_y_axis ();

	void set_y_axis (int y);

};

#endif