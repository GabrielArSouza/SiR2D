#include "xml-parser.h"
using namespace tinyxml2;

void parser_xml (std::string filename)
{
    XMLDocument doc;
    doc.LoadFile( filename.c_str() );

	XMLElement *pRoot = doc.FirstChildElement("scene")->FirstChildElement("canvas");
	
	Canvas canvas;
	std::vector<Shape*> shapes;

	if (pRoot != NULL)
	{
		std::string height, width, color_bkg;
		if ( pRoot->Attribute("height") != NULL)
			height = pRoot->Attribute("height");
		else throw INVALID_CANVAS;
		
		if (pRoot->Attribute("width") != NULL)
			width = pRoot->Attribute("width");
		else throw INVALID_CANVAS;

		canvas = Canvas(std::stoi(width), std::stoi(height));
		if (pRoot->Attribute("color") != NULL)
		{
			color_bkg = pRoot->Attribute("color");
			try	{
				Color color;
				color = color.get_color(color_bkg);
				canvas.set_color_bkg(color);
			}
			catch(const std::exception& e){
				std::cerr << e.what() << '\n';
			}
		}

		pRoot = pRoot->NextSiblingElement( "shape" );
		while (pRoot != NULL)
		{
			std::string type;
			if (pRoot->Attribute("type") != NULL)
				type = pRoot->Attribute("type");
			else throw INVALID_SHAPE;

			// verify 
			if (type.compare("circle") == 0)
			{
				try {

					Circle *circle;
					create_circle(circle, pRoot);
					canvas.add_new_shape(circle);

				} catch(std::string e){
					std::cout << e << std::endl;
				}
			}
			else if (type.compare("line") == 0)
				std::cout << "This is a line\n";
			else if (type.compare("triangle") == 0)
				std::cout << "This is a triangle\n";
			
			// Get next child
			pRoot = pRoot->NextSiblingElement( "shape" );
		}
	}

	canvas.draw();

	Raster raster = Raster (&canvas, filename);
	raster.draw();
}

void create_circle (Circle *&circle, XMLElement * element )
{
	// Attributes of a circle
	std::string cx, cy, r, stroke, fill;
	
	// -----------------------------------
	// Check required attributes
	// -----------------------------------
	if (element->Attribute("cx") != NULL)
		cx = element->Attribute("cx");
	else throw INVALID_CIRCLE;

	if (element->Attribute("cy") != NULL)
		cy = element->Attribute("cy");
	else throw INVALID_CIRCLE;

	if (element->Attribute("r") != NULL)
		r  = element->Attribute("r");
	else throw INVALID_CIRCLE;
	// -----------------------------------

	// ----------------------------------------
	// Try get circle colors
	// ----------------------------------------
	if (element->Attribute("stroke") != NULL)
		stroke = element->Attribute("stroke");
	
	if (element->Attribute("fill") != NULL)
		fill = element->Attribute("fill");
	// -----------------------------------------

	// Define a basic circle
	circle = new Circle(POINT{std::stoi(cx), std::stoi(cy)}, std::stoi(r));

	// -----------------------------------------------
	// Check and get colors 
	// -----------------------------------------------
	if (!stroke.empty()){
		try {
			Color c_stroke;
			c_stroke = c_stroke.get_color(stroke);
			circle->set_color(c_stroke);	
		}catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	
	if (!fill.empty()){
		try {
			Color c_fill;
			c_fill = c_fill.get_color(fill);
			circle->set_fill(c_fill);
		}catch(const std::exception& e)	{
			std::cerr << e.what() << '\n';
		}
	}
	// -------------------------------------------------
}