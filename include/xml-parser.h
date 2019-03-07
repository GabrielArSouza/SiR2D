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

#define INVALID_CANVAS "Invalid canvas specification"
#define INVALID_SHAPE  "Invalid shape specification"
#define INVALID_CIRCLE "Invalid circle specification"

using namespace tinyxml2;

void parser_xml (std::string filename);
Circle create_circle (XMLElement *element );

#endif