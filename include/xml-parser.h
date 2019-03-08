#ifndef _XML_PARSER_H_
#define _XML_PARSER_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "tinyxml2.h"
#include "raster.h"
#include "line.h"
#include "circle.h"
#include "triangle.h"

// Define exceptions
#define INVALID_CANVAS "Invalid canvas specification"
#define INVALID_SHAPE  "Invalid shape specification"
#define INVALID_CIRCLE "Invalid circle specification"

using namespace tinyxml2;

/**
 * @brief Parse and interprets a xml archive
 * @param filename the filename
 */
void parser_xml (std::string filename);

/**
 * @brief Create a circle object of a xml declaration
 * 
 * @param circle The object circle for creation
 * @param element The element xml with the description circle
 */
void create_circle (Circle *&circle, XMLElement *element );

#endif