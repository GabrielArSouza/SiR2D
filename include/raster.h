#ifndef _RASTER_H_
#define _RASTER_H_

#include "canvas.h"
// #include <string>
#include <fstream>
#include <iostream>

class Raster {

private:
	Canvas * canvas;

	std::string filename = "out";

public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      canvas  The canvas
	 */
	Raster (Canvas * canvas);

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      canvas    The canvas
	 * @param[in]  filename  The filename
	 */
	Raster (Canvas * canvas, std::string filename);

	/**
	 * @brief      draw canvas
	 */
	void draw ();

};

#endif