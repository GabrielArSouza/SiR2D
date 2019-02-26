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

	Point p3 = Point(10,189);
	Point p4 = Point(189,10);

	Line line = Line(&p1, &p2, &color, &color);
	Line line2 = Line (&p3, &p4, &color, &color);
	Line line3 = Line (&p1, &p4, &color, &color);	

	canvas.draw(&line, &color);
	canvas.draw(&line3, &color);

	Raster raster = Raster (&canvas, filename);
	raster.draw();

	return 0;
}