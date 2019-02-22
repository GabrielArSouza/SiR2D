#include <iostream>
#include <fstream>
#include <string>

#include "raster.h"

int main ()
{

	std::string filename = "teste";

	Canvas canvas = Canvas(400, 400);
	Raster raster = Raster (&canvas, filename);
	raster.draw();

	return 0;
}