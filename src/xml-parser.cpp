#include "xml-parser.h"
using namespace tinyxml2;


void parser_xml (std::string filename)
{
    XMLDocument doc;
    doc.LoadFile( filename.c_str() );

    XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
	std::string title = titleElement->GetText();
	std::cout << "Name of play (1): " << title << std::endl;

	XMLText* textNode = titleElement->FirstChild()->ToText();
	title = textNode->Value();
	std::cout << "Name of play (2): " << title << std::endl;
}