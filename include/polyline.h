#ifndef _POLYLINE_H_
#define _POLYLINE_H_

#include <vector>

#include "shape.h"
#include "line.h"

class Polyline : public Shape{

private:
    std::vector<Shape*> lines;
    Color fill_color;

public:
    Polyline( std::vector<Shape*> lines, const Color &color = Color::BLACK );

    Polyline( std::vector<POINT> points, const Color &color = Color::BLACK );

    ~Polyline();

    void draw();

    std::string to_string();

};

#endif