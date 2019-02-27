#include <iostream>
#include <fstream>
#include <string>

#include "raster.h"
#include "line.h"

int main ()
{

	std::string filename = "teste";

	Canvas canvas = Canvas(200, 200);
	
	Color color = Color(4,255,4);
	
	// create a line
	POINT p1 = {10, 10};
	POINT p2 = {189, 189};
	POINT p3 = {10,189};
	POINT p4 = {189,10};

	Line line1 = Line(&p1, &p2, &color, &color);
	canvas.add_new_shape(&line1);

	Line line2 = Line (&p1, &p4, &color, &color);	
	canvas.add_new_shape(&line2);

	Line line3 = Line (&p3, &p4, &color, &color);
	canvas.add_new_shape(&line3);
	
	canvas.draw();

	Raster raster = Raster (&canvas, filename);
	raster.draw();

	return 0;
}