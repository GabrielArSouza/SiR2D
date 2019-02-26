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
	POINT p1 = {10, 10};
	POINT p2 = {189, 189};
	POINT p3 = {10,189};
	POINT p4 = {189,10};
	POINT p5 = {100,10};
	POINT p6 = {100,189};

	Line line1 = Line(&p1, &p2, &color, &color);
	Line line2 = Line(&p1, &p3, &color, &color); 
	Line line3 = Line (&p1, &p4, &color, &color);	
	Line line4 = Line (&p3, &p4, &color, &color);
	Line line5 = Line (&p5, &p6, &color, &color);
	//canvas.draw(&line1, &color);
	canvas.draw(&line2, &color);
	//canvas.draw(&line3, &color);
	canvas.draw(&line5, &color);

	Raster raster = Raster (&canvas, filename);
	raster.draw();

	return 0;
}