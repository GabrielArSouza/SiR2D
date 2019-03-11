#include <iostream>
#include <fstream>
#include <string>

#include "raster.h"
#include "line.h"
#include "circle.h"
#include "triangle.h"
#include "xml-parser.h"


int main (int argc, char *argv[])
{

	std::string filename, imagename;
	if (argc == 2)
	{
		filename = argv[1];
		imagename  = "out";
	} else if (argc == 3) 
	{
		filename = argv[1];
		imagename = argv[2];
	} else 
	{
		std::cout << "Please, specify the xml file with the scene specification.\n";
		std::cout << "./exe.out <xml_file> <image_name>\n";
		return 0;	
	}

	try	{
		parser_xml(filename, imagename);	
	}
	catch(const char * e)	{
		std::cerr << e << '\n';
	}
	
	return 0;
	
}