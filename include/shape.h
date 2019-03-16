#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "color.h"
#include "common.h"

#include <vector>
#include <string>

/**
 * @brief The class for Shape
 * 
 */
class Shape {

protected:

	Color color; //<! border color shape
	std::vector<POINT> pixels; // border points
	
	bool floodfill; // if use fooldfill algorithm
	bool polygon;   // if is a polygon

public:

	/**
	 * @brief Construct a new Shape object
	 * 
	 * @param color the border color
	 * @param floodfill   if use the flood fill algorithm
	 * @param polygon  if is a polygon
	 */
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

	/**
	 * @brief Set the color object
	 * 
	 * @param color the new border color
	 */
	void set_color (const Color &color);

	/**
	 * @brief Get the pixels object
	 * 
	 * @return std::vector<POINT> the points vector
	 */
	std::vector<POINT> get_pixels ();

	/**
	 * @brief class description
	 *  
	 * @return std::string the description string
	 */
	virtual std::string to_string();

	/**
	 * @brief Get the fill object
	 * 
	 * @return Color& the color
	 */
	virtual Color& get_fill();

	/**
	 * @brief Get the pfloodfill object
	 * 
	 * @return std::vector<POINT> the vector of points
	 */
	virtual std::vector<POINT> get_pfloodfill();

	/**
	 * @brief scan line algorithm
	 * 
	 * @param heght canvas height
	 * @return std::vector<POINT> the vector points for coloring 
	 */
    virtual std::vector<POINT> scanline(int heght);
	
	/**
	 * @brief if use a flood fill algorithm
	 * 
	 * @return true if use flood fill algorithm, false otherwise
	 */
	bool is_floodfill();

	/**
	 * @brief Set the floodfill object
	 * 
	 * @param value the new value 
	 */
    void set_floodfill(bool value);

	/**
	 * @brief if is a polygon
	 * 
	 * @return true if a polygon, false othewise
	 */
	bool is_polygon();
};

#endif