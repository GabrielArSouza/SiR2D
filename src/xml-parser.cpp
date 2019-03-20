#include "xml-parser.h"
using namespace tinyxml2;

void parser_xml (std::string filename, std::string imagename)
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
			{
				try {

					Line *line;
					create_line(line, pRoot);
					canvas.add_new_shape(line);

				} catch(std::string e){
					std::cout << e << std::endl;
				}
			}
			else if (type.compare("triangle") == 0)
				std::cout << "This is a triangle\n";
			else if (type.compare("polyline") == 0)
			{
				try{
					Polyline * pl;
					create_polyline(pl, pRoot);
					canvas.add_new_shape(pl);
				}catch(std::string e){
					std::cout << e << std::endl;
				}
			}
			
			// Get next child
			pRoot = pRoot->NextSiblingElement( "shape" );
		}
	}

	canvas.draw();

	Raster raster = Raster (&canvas, imagename);
	raster.draw();
}

void create_circle (Circle *&circle, XMLElement * element )
{
	// Attributes of a circle
	std::string cx, cy, r, stroke, fill, point;
	
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

	if (element->Attribute("pcolor") != NULL)
		point = element->Attribute("pcolor");

	// Define a basic circle
	circle = new Circle(POINT{std::stoi(cx), std::stoi(cy)}, std::stoi(r), true);

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

void create_line (Line *&line, XMLElement *element )
{
	// Attributes of a line
	std::string x1, y1, x2, y2, stroke;
	
	// -----------------------------------
	// Check required attributes
	// -----------------------------------
	if (element->Attribute("x1") != NULL)
		x1 = element->Attribute("x1");
	else throw INVALID_LINE;

	if (element->Attribute("y1") != NULL)
		y1 = element->Attribute("y1");
	else throw INVALID_LINE;

	if (element->Attribute("x2") != NULL)
		x2  = element->Attribute("x2");
	else throw INVALID_LINE;

	if (element->Attribute("y2") != NULL)
		y2  = element->Attribute("y2");
	else throw INVALID_LINE;
	// -----------------------------------
	
	// ----------------------------------------
	// Try get line color
	// ----------------------------------------
	if (element->Attribute("stroke") != NULL)
		stroke = element->Attribute("stroke");

	line = new Line(POINT{std::stoi(x1), std::stoi(y1)}, 
					POINT{std::stoi(x2), std::stoi(y2)});

	// -----------------------------------------------
	// Check and get color 
	// -----------------------------------------------
	if (!stroke.empty()){
		try {
			Color c_stroke;
			c_stroke = c_stroke.get_color(stroke);
			line->set_color(c_stroke);	
		}catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

}

void create_polyline (Polyline *&pl, XMLElement *element)
{
	// Attributes of a polyline
	std::string points, stroke, fill, point, polygon;
	
	// -----------------------------------
	// Check required attributes
	// -----------------------------------
	if (element->Attribute("points") != NULL)
		points = element->Attribute("points");
	else throw INVALID_POLYLINE;
	// -----------------------------------
	
	// get all points of polyline
	std::vector<POINT> polypoints = parser_many_points(points);

	// check if is a polygon
	bool is_polygon = false;
	if (element->Attribute("polygon") != NULL)
	{
		polygon = element->Attribute("polygon");
		if (polygon.compare("true") == 0) is_polygon = true;
	}

	// ----------------------------------------
	// Try get line color
	// ----------------------------------------
	if (element->Attribute("stroke") != NULL)
		stroke = element->Attribute("stroke");

	if (element->Attribute("fill") != NULL)
		fill = element->Attribute("fill");
	// -----------------------------------------

	if (element->Attribute("pcolor") != NULL)
		point = element->Attribute("pcolor");

	if ( !point.empty() )
	{
		std::vector<POINT> u_point = parser_many_points(point);
		pl = new Polyline(polypoints, is_polygon, true, u_point);
	}else {
		pl = new Polyline(polypoints, is_polygon, false);
	}

	// -----------------------------------------------
	// Check and get color 
	// -----------------------------------------------
	if (!stroke.empty()){
		try {
			Color c_stroke;
			c_stroke = c_stroke.get_color(stroke);
			pl->set_color(c_stroke);	
		}catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	if (!fill.empty()){
		try {
			Color c_fill;
			c_fill = c_fill.get_color(fill);
			pl->set_fill(c_fill);
		}catch(const std::exception& e)	{
			std::cerr << e.what() << '\n';
		}
	}
}

std::vector<POINT> parser_many_points (std::string points)
{

	// parser all points
	std::vector<std::string> results;
	boost::split(results, points, [](char c){return c == ' ';});
	std::vector<POINT> polypoints;

	// generate all points
	std::string aux;
	std::vector<std::string> u_point;
	for (unsigned int i=0; i<results.size(); i++){
		aux = results[i];
		boost::split(u_point, aux, [](char c){return c == ',';});
		polypoints.push_back(POINT{std::stoi(u_point[0]), std::stoi(u_point[1])});
	}

	return polypoints;
}