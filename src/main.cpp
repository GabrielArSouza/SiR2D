#include <iostream>
#include <fstream>
#include <string>

#include "raster.h"
#include "line.h"
#include "circle.h"
#include "triangle.h"
#include "xml-parser.h"


int main ()
{
	// std::string filename = "teste";

	// Canvas canvas = Canvas(200, 200);
	
	// // create a line
	// POINT p1 = {20, 20};
	// POINT p2 = {20, 180};

	// Line line1 = Line(&p1, &p2, Color::GREEN);
	// canvas.add_new_shape(&line1);

	// Circle circle = Circle (POINT {100,100}, 80, Color::BLACK);
	// canvas.add_new_shape(&circle);
	
	// Triangle trig = Triangle(POINT{20,20}, POINT{140,60}, POINT{140,140}, Color::PINK);
	// canvas.add_new_shape(&trig);
	
	// canvas.draw();

	// Raster raster = Raster (&canvas, filename);
	// raster.draw();

	parser_xml("dream.xml");

	return 0;
}