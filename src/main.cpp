#include <iostream>
#include <fstream>
#include <string>

#include "raster.h"
#include "line.h"
#include "circle.h"

int main ()
{

	std::string filename = "teste";

	Canvas canvas = Canvas(200, 200);
	
	Color color = Color(4,255,4);
	
	// create a line
	// POINT p1 = {20, 20};
	// POINT p2 = {20, 180};
	// POINT p3 = {180, 20};
	// POINT p4 = {180, 180};
	// POINT p5 = {100, 100};

	// Line line1 = Line(&p1, &p2, BLACK);
	// canvas.add_new_shape(&line1);

	// Line line2 = Line (&p1, &p3, &color, &color);	
	// canvas.add_new_shape(&line2);

	// Line line3 = Line (&p1, &p5, &color, &color);
	// canvas.add_new_shape(&line3);

	// Line line4 = Line (&p5, &p4, &color, &color);
	// canvas.add_new_shape(&line4);

	// Line line5 = Line (&p3, &p2, &color, &color);
	// canvas.add_new_shape(&line5);
	
	// Line line6 = Line (&p2, &p4, &color, &color);
	// canvas.add_new_shape(&line6);

	// Line line7 = Line (&p3, &p4, &color, &color);
	// canvas.add_new_shape(&line7);

	Circle circle = Circle (POINT {100,100}, 80, BLACK);
	canvas.add_new_shape(&circle);
	canvas.draw();

	Raster raster = Raster (&canvas, filename);
	raster.draw();

	return 0;
}