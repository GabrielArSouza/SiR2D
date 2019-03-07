#include "xml-parser.h"
using namespace tinyxml2;


void parser_xml (std::string filename)
{
    XMLDocument doc;
    doc.LoadFile( filename.c_str() );

	XMLElement *pRoot = doc.FirstChildElement("scene")->FirstChildElement("canvas");
	if (pRoot != NULL)
	{
		std::cout << "height: " << pRoot->Attribute("height") 
			<< ", width: " << pRoot->Attribute("width") << std::endl;

		while (pRoot != NULL)
		{
			// Get next child
			pRoot = pRoot->NextSiblingElement( "shape" );
			std::string type = pRoot->Attribute("type");
			// Is a circle?
			if (type.compare("circle"))
				std::cout << "this is a circle\n";

		}
	}
	
	// pParm = pRoot->FirstChildElement("circle");
	// std::cout << "cx:" << pParm->Attribute("cx") << ", cy: " << pParm->Attribute("cy") 
	// 			<< ", r: " << pParm->Attribute("r") << ", stroke: " << pParm->Attribute("stroke")
	// 			<< ", fill: " << pParm->Attribute("fill");
	
    // XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
	// std::string title = titleElement->GetText();
	// std::cout << "Name of play (1): " << title << std::endl;

	// XMLText* textNode = titleElement->FirstChild()->ToText();
	// title = textNode->Value();
	// std::cout << "Name of play (2): " << title << std::endl;
}