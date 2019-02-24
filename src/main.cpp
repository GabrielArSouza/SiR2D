#include <iostream>
#include <fstream>
#include <string>

#include "raster.h"

int main ()
{

	std::string filename = "teste";

	Canvas canvas = Canvas(200, 200);
	
	Color color = Color(4,255,4);
	
	// create a line
	Point p1 = Point (10, 10);
	Point p2 = Point (189, 189);

	Line line = Line(&p1, &p2, &color, &color);

	canvas.draw(&line, &color);

	Raster raster = Raster (&canvas, filename);
	raster.draw();

	return 0;
}